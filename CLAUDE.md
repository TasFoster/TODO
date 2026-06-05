# CLAUDE.md

Этот файл предоставляет инструкции Claude Code (claude.ai/code) при работе с данным репозиторием.

## Сборка и запуск

**Требования:** Qt 6.5+ (Core, Widgets, Sql, LinguistTools), CMake 3.19+, MinGW 64-bit

**Сборка через Qt Creator (рекомендуется):** Открыть `CMakeLists.txt`, выбрать кит `Desktop_Qt_6_10_0_MinGW_64_bit-Debug`, затем Ctrl+R для сборки и запуска.

**Сборка через CLI:**
```powershell
cmake -B build -S .
cmake --build build --config Debug
.\build\Desktop_Qt_6_10_0_MinGW_64_bit-Debug\Todo.exe
```

Автоматических тестов нет.

## Архитектура

Приложение — Qt 6 десктопный менеджер задач с базой данных SQLite. Организовано в виде простой слоистой структуры:

**Слой данных — `corelogic.{h,cpp}`**
Центральный класс, содержащий структуру `DataTask` (`id`, `title`, `description`, `status`, `created_at`, `deadline`, `tag`) и все операции с базой данных (`GetListTask()`, `SaveTask()`). Файл базы данных SQLite — `my_db.db`, создаётся рядом с исполняемым файлом. Соединение открывается и закрывается при каждой операции.

**Слой UI — три класса виджетов:**
- `MainWindow` — корневое окно (800×600). Владеет экземпляром `CoreLogic`, `QListWidget` для списка задач, верхней и нижней панелями. `updateListTask()` перестраивает список из базы данных; `on_addTask_clicked()` открывает `CreateTask` как модальное окно.
- `CreateTask` — модальный диалог создания задачи. Испускает `CreatTaskSignal(DataTask*)` при подтверждении; MainWindow связывает этот сигнал с `CoreLogic::SaveTask`, затем с `updateListTask`.
- `Task` — кастомный `QWidget`, используемый как элемент списка. Отображает заголовок, описание, метки времени, тег и `QComboBox` статуса.

**Поток сигнал/слот:**
```
MainWindow → открывает CreateTask (модально)
CreateTask → испускает CreatTaskSignal(DataTask*)
MainWindow → вызывает CoreLogic::SaveTask, затем updateListTask
```

## Незавершённые области

- `SaveTask()` сейчас сохраняет только `title` и `description`; поля `deadline`, `created_at`, `tag` и `status` в базу данных не записываются.
- `validDataTime()` в `CoreLogic` — заглушка, всегда возвращает `true`.
- Обработчик кнопки настроек (`on_setings_clicked`) пустой.
- `QComboBox` статуса в виджете `Task` не имеет подключённого обработчика изменений.
- `cteattask.{h,cpp,ui}` — неиспользуемый устаревший код (не включён в CMakeLists.txt).

## Локализация

Строки интерфейса на русском языке. Файл перевода Qt Linguist `Todo_ru_RU.ts` существует, но пустой. `main.cpp` загружает переводы из `:/i18n/` при запуске через `QTranslator`.
