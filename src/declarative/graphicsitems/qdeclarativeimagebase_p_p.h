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

#ifndef QDECLARATIVEIMAGEBASE_P_P_H
#define QDECLARATIVEIMAGEBASE_P_P_H

#include <qdeclarativeimplicitsizeitem_p_p.h>
#include <qdeclarativepixmapcache_p.h>
#include <QtCore/QPointer>

QT_BEGIN_NAMESPACE

class QNetworkReply;
class QDeclarativeImageBasePrivate : public QDeclarativeImplicitSizeItemPrivate
{
   Q_DECLARE_PUBLIC(QDeclarativeImageBase)

 public:
   QDeclarativeImageBasePrivate()
      : status(QDeclarativeImageBase::Null),
        progress(0.0),
        explicitSourceSize(false),
        async(false),
        cache(true),
        mirror(false) {
      QGraphicsItemPrivate::flags = QGraphicsItemPrivate::flags & ~QGraphicsItem::ItemHasNoContents;
   }

   QDeclarativePixmap pix;
   QDeclarativeImageBase::Status status;
   QUrl url;
   qreal progress;
   QSize sourcesize;
   bool explicitSourceSize : 1;
   bool async : 1;
   bool cache : 1;
   bool mirror: 1;
};

QT_END_NAMESPACE

#endif
