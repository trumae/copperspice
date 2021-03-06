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

#ifndef QIfThenClause_P_H
#define QIfThenClause_P_H

#include <qtriplecontainer_p.h>

QT_BEGIN_NAMESPACE

namespace QPatternist {

class IfThenClause : public TripleContainer
{
 public:
   IfThenClause(const Expression::Ptr &test,
                const Expression::Ptr &then,
                const Expression::Ptr &el);

   virtual bool evaluateEBV(const DynamicContext::Ptr &context) const;
   virtual Item::Iterator::Ptr evaluateSequence(const DynamicContext::Ptr &context) const;
   virtual Item evaluateSingleton(const DynamicContext::Ptr &context) const;
   virtual void evaluateToSequenceReceiver(const DynamicContext::Ptr &context) const;

   virtual SequenceType::List expectedOperandTypes() const;
   virtual Expression::Ptr compress(const StaticContext::Ptr &context);

   virtual SequenceType::Ptr staticType() const;
   virtual ExpressionVisitorResult::Ptr accept(const ExpressionVisitor::Ptr &visitor) const;
   /**
    * @returns IDIfThenClause
    */
   virtual ID id() const;
   virtual QList<QExplicitlySharedDataPointer<OptimizationPass> > optimizationPasses() const;
   //virtual Properties properties() const;
};
}

QT_END_NAMESPACE

#endif
