#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "clientmodel.h"
#include "util.h"
#include "guiutil.h"
#include "guiconstants.h"
#include "version.h"

using namespace GUIUtil;

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    GUIUtil::restoreWindowGeometry("nAboutDialogWindow", this->size(), this);
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    GUIUtil::saveWindowGeometry("nAboutDialogWindow", this);
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
