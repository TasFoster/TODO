#include "task.h"
#include "ui_task.h"

static QString statusColor(const QString &status)
{
    if (status == "В процессе") return "#f97316";
    if (status == "Завершена")  return "#22c55e";
    if (status == "Отложена")   return "#94a3b8";
    if (status == "Провалена")  return "#ef4444";
    return "#3b82f6";
}

Task::Task(const DataTask *taskData, QWidget *parent)
    : QWidget(parent), ui(new Ui::Task)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);
    taskId = taskData->id;

    ui->titleLabel->setText(taskData->title);
    ui->descLabel->setText(taskData->description);
    ui->descLabel->setVisible(!taskData->description.isEmpty());

    if (taskData->tag.isEmpty()) {
        ui->tagLabel->hide();
    } else {
        ui->tagLabel->setText(taskData->tag);
    }

    if (taskData->deadline.isEmpty()) {
        ui->deadlineLabel->hide();
    } else {
        ui->deadlineLabel->setText("  " + taskData->deadline);
    }

    ui->statusCombo->addItems({"Активная", "В процессе", "Завершена", "Отложена", "Провалена"});
    ui->statusCombo->setCurrentText(taskData->status.isEmpty() ? "Активная" : taskData->status);

    applyStatusStyle(ui->statusCombo->currentText());

    connect(ui->statusCombo, &QComboBox::currentTextChanged, this, [this](const QString &status) {
        applyStatusStyle(status);
        emit statusChanged(taskId, status);
    });

    connect(ui->deleteBtn, &QPushButton::clicked, this, [this]() {
        emit deleteRequested(taskId);
    });
}

Task::~Task()
{
    delete ui;
}

void Task::applyStatusStyle(const QString &status)
{
    QString color = statusColor(status);

    setStyleSheet(QString(
        "background-color: #2a2a3e;"
        "border-radius: 12px;"
        "border-left: 5px solid %1;"
    ).arg(color));

    ui->statusCombo->setStyleSheet(QString(
        "QComboBox {"
        "  background-color: %1;"
        "  color: white;"
        "  border: none;"
        "  border-radius: 6px;"
        "  padding: 3px 8px;"
        "  font-size: 12px;"
        "  font-weight: bold;"
        "}"
        "QComboBox::drop-down { border: none; width: 16px; }"
        "QComboBox QAbstractItemView {"
        "  background-color: #252535;"
        "  color: #e2e8f0;"
        "  selection-background-color: %1;"
        "  border: 1px solid #3d3d55;"
        "}"
    ).arg(color));
}
