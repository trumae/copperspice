/***********************************************************************
*
* Copyright (c) 2012-2016 Barbara Geller
* Copyright (c) 2012-2016 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or 
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see 
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#include <qbasictimer.h>
#include <qcoreapplication.h>
#include <qabstracteventdispatcher.h>

QT_BEGIN_NAMESPACE

void QBasicTimer::start(int msec, QObject *obj)
{
   stop();
   if (obj) {
      id = obj->startTimer(msec);
   }
}

/*!
    Stops the timer.

    \sa start() isActive()
*/
void QBasicTimer::stop()
{
   if (id) {
      QAbstractEventDispatcher *eventDispatcher = QAbstractEventDispatcher::instance();
      if (eventDispatcher) {
         eventDispatcher->unregisterTimer(id);
      }
   }
   id = 0;
}

QT_END_NAMESPACE
