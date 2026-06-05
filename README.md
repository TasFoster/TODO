# ✅ Todo

*Десктопный менеджер задач на Qt 6 с хранением в SQLite.*

![C++](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)
![Qt6](https://img.shields.io/badge/Qt-6.5%2B-41CD52?logo=qt&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-3.19%2B-064F8C?logo=cmake&logoColor=white)
![SQLite](https://img.shields.io/badge/SQLite-embedded-003B57?logo=sqlite&logoColor=white)
![Django](https://img.shields.io/badge/Django-вложенный-092E20?logo=django&logoColor=white)

---

## ✨ Возможности

- **Создание задач** — модальный диалог `CreateTask` с полями: заголовок, описание, дедлайн, дата создания, тег и статус.
- **Список задач** — главное окно строит список из базы (`SELECT * FROM Tasks ORDER BY id DESC`), каждый элемент — кастомный виджет `Task`.
- **Смена статуса** — выпадающий список статусов в карточке задачи (по умолчанию «Активная») с записью в базу через `UpdateTaskStatus()`.
- **Удаление задач** — `DeleteTask()` убирает задачу из базы и обновляет список.
- **Хранение в SQLite** — таблица `Tasks` (`id`, `title`, `description`, `created_at`, `deadline`, `tags`, `status`) создаётся автоматически в файле `my_db.db` рядом с исполняемым файлом.
- **Локализация** — интерфейс на русском; `main.cpp` подгружает переводы Qt Linguist из `:/i18n/` (файл `Todo_ru_RU.ts`).
- **Оформление** — кастомный шрифт Segoe UI и тёмные подсказки (tooltip) через глобальный stylesheet.

> Часть полей и обработчиков ещё дорабатывается (см. раздел «Незавершённые области» в `CLAUDE.md`).

## 🛠 Стек

| Компонент | Технология |
|---|---|
| Язык | C++ |
| GUI | Qt 6 (Core, Widgets, Sql, LinguistTools) |
| Сборка | CMake 3.19+, MinGW 64-bit |
| База данных | SQLite (драйвер `QSQLITE`) |
| Перевод | Qt Linguist (`QTranslator`) |

## 🚀 Сборка и запуск

**Требования:** Qt 6.5+, CMake 3.19+, MinGW 64-bit.

```powershell
cmake -B build -S .
cmake --build build --config Debug
.\build\Desktop_Qt_6_10_0_MinGW_64_bit-Debug\Todo.exe
```

Либо открыть `CMakeLists.txt` в Qt Creator, выбрать кит `Desktop_Qt_6_10_0_MinGW_64_bit-Debug` и нажать `Ctrl+R`.

## 🐍 Вложенный Django-проект

В каталоге `TODO/TODO/TODO_Project` лежит **отдельный** учебный Django-проект (не связанный со сборкой Qt-приложения) — веб-вариант того же менеджера задач:

- **`Model_TODO`** — приложение задач: модель `Task` (`name_task`, `discription`, `date`, `time`), вьюхи списка и создания задач (`viewTasks`, `createTask`).
- **`Registration`** — кастомный пользователь `MyUser` (`AbstractUser`) с привязкой задач через `ManyToManyField`.
- Зависимости: `django`, `psycopg2-binary` (см. `TODO/TODO/requirements.txt`).

Запуск:

```powershell
cd TODO\TODO\TODO_Project
..\.venv\Scripts\Activate.ps1
pip install -r ..\requirements.txt
python manage.py migrate
python manage.py runserver
```

## 📂 Структура

```
TODO/
├── CMakeLists.txt          # конфигурация сборки Qt/CMake
├── main.cpp                # точка входа, шрифт, стили, загрузка переводов
├── mainwindow.{h,cpp,ui}   # главное окно, список задач
├── createtask.{h,cpp,ui}   # модальный диалог создания задачи
├── task.{h,cpp,ui}         # виджет-карточка задачи
├── corelogic.{h,cpp}       # слой данных: DataTask + операции с SQLite
├── Todo_ru_RU.ts           # файл перевода Qt Linguist
├── CLAUDE.md               # заметки по архитектуре
└── TODO/TODO_Project/      # вложенный Django-проект (веб-версия)
    ├── manage.py
    ├── Model_TODO/         # приложение задач
    └── Registration/       # пользователи и регистрация
```

---

<sub>Учебный pet-проект. README оформлен с помощью Claude Code.</sub>
