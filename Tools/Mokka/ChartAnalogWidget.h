/* 
 * The Biomechanical ToolKit
 * Copyright (c) 2009-2011, Arnaud Barré
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *     * Redistributions of source code must retain the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials
 *       provided with the distribution.
 *     * Neither the name(s) of the copyright holders nor the names
 *       of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ChartAnalogWidget_h
#define ChartAnalogWidget_h

#include "Acquisition.h"

#include <QVTKWidget.h>

class vtkChartXY;
class vtkDoubleArray;

class QDragEnterEvent;
class QDropEvent;

class ChartOptionsWidget;

class ChartAnalogWidget : public QVTKWidget
{
  Q_OBJECT
  
public:
  ChartAnalogWidget(QWidget* parent = 0);
  ~ChartAnalogWidget();
  
  void initialize();
  Acquisition* acquisition() {return this->mp_Acquisition;};
  void setAcquisition(Acquisition* acq) {this->mp_Acquisition = acq;};
  vtkDoubleArray* frameArray() {return this->mp_ArrayFrames;};
  void setFrameArray(vtkDoubleArray* array);
  void show(bool s);
  ChartOptionsWidget* options() {return mp_ChartOptions;};
  void toggleOptions(const QPoint& pos);
  
  void copy(ChartAnalogWidget* source);
  
public slots:
  void removePlot(int index);
  void render();
  void setPlotLineColor(const QList<int>& indices, const QColor& color);
  void setPlotLineWidth(const QList<int>& indices, double value);

  
protected:
  virtual void dragEnterEvent(QDragEnterEvent *event);
  virtual void dropEvent(QDropEvent* event);
  virtual void paintEvent(QPaintEvent* event);
  
private:
  Acquisition* mp_Acquisition;
  vtkChartXY* mp_VTKChart;
  vtkDoubleArray* mp_ArrayFrames;
  ChartOptionsWidget* mp_ChartOptions;
};

#endif // ChartAnalogWidget_h