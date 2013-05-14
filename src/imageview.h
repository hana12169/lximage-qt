/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2013  <copyright holder> <email>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef LXIMAGE_IMAGEVIEW_H
#define LXIMAGE_IMAGEVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QImage>

namespace LxImage {

class ImageView : public QGraphicsView {
  Q_OBJECT

public:
  ImageView(QWidget* parent = 0);
  virtual ~ImageView();

  void setImage(QImage image);

  QImage image() {
    return image_;
  }

  void setScaleFactor(double scale);

  double scaleFactor() {
    return scaleFactor_;
  }

  void zoomIn();
  void zoomOut();
  void zoomFit();
  void zoomOriginal();

protected:
  virtual void wheelEvent(QWheelEvent* event);
  virtual void resizeEvent(QResizeEvent* event);

private:
  QGraphicsScene* scene_; // the topmost container of all graphic items
  QGraphicsRectItem* imageItem_; // the rect item used to draw the image
  QImage image_; // image to show
  double scaleFactor_;
};

}

#endif // LXIMAGE_IMAGEVIEW_H