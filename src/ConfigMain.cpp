#include <fcitx-config/xdg.h>

#include <fcitx-qt/fcitxqtkeysequencewidget.h>

#include "ConfigMain.h"
#include "ui_ConfigMain.h"
#include "Common.h"


namespace fcitx_rime {
  ConfigMain::ConfigMain(QWidget* parent) :
    FcitxQtConfigUIWidget(parent), m_ui(new Ui::MainUI) {
    this->setMinimumSize(500, 500);
    m_ui->setupUi(this);
    this->rime = FcitxRimeConfigCreate();
    FcitxRimeConfigStart(this->rime);
    this->test();
  }
  ConfigMain::~ConfigMain() {
    delete m_ui;
  }
  void ConfigMain::createGeneralWidget() {
    QVBoxLayout* layout = new QVBoxLayout(this);
    FcitxQtKeySequenceWidget* keyseq1 = new FcitxQtKeySequenceWidget();
    layout->addWidget(keyseq1);
  }
  
  QString ConfigMain::icon() {
    return "fcitx-rime";
  }
  QString ConfigMain::addon() {
    return "fcitx-rime";
  }
  QString ConfigMain::title() {
    return _("Fcitx Rime Config GUI Tool");
  }
  void ConfigMain::load() {
  }
  void ConfigMain::save() {
  }
  
  void ConfigMain::test() {
    RimeConfig* fcitx_rime_config_default = FcitxRimeConfigOpenDefault(this->rime);
    int page_size = 0;
    bool suc = this->rime->api->config_get_int(fcitx_rime_config_default, "menu.page_size", &page_size);
    printf("Success? %d\n", suc);
    printf("%d\n", page_size);
  }
}
