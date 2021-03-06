#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScrollBar>

#include "pixmapbutton.h"
#include "scene_base.h"

class SettingsMenu : public QGraphicsScene {
  Q_OBJECT

 public:
  SettingsMenu();

  void Resize();
  void keyPressEvent(QKeyEvent* event) override;

 public slots:
  void ChangeKey();

 signals:
  void BackToMenu();
  void SwitchMusic();

 private:
  QString KeyToString(QKeyEvent* event) const;

  PixmapButton* back_to_menu_;
  PixmapButton* music_checkbox_;

  QVector<PixmapButton*> buttons_;
  QVector<QGraphicsTextItem*> descriptions_;

  ActionType ch_button_type = ActionType::NONE;
  PixmapButton* ch_button;

  QFont font_ = QFont("Alagard");
};

#endif  // SETTINGSMENU_H
