/*******************************************************************************
 *                                                                             *
 * Author    :  Angus Johnson                                                  *
 * Version   :  5.1.6                                                          *
 * Date      :  23 May 2013                                                    *
 * Website   :  http://www.angusj.com                                          *
 * Copyright :  Angus Johnson 2010-2013                                        *
 *                                                                             *
 * License:                                                                    *
 * Use, modification & distribution is subject to Boost Software License Ver 1.*
 * http://www.boost.org/LICENSE_1_0.txt                                        *
 *                                                                             *
 * Attributions:                                                               *
 * The code in this library is an extension of Bala Vatti's clipping algorithm:*
 * "A generic solution to polygon clipping"                                    *
 * Communications of the ACM, Vol 35, Issue 7 (July 1992) pp 56-63.            *
 * http://portal.acm.org/citation.cfm?id=129906                                *
 *                                                                             *
 * Computer graphics and geometric modeling: implementation and algorithms     *
 * By Max K. Agoston                                                           *
 * Springer; 1 edition (January 4, 2005)                                       *
 * http://books.google.com/books?q=vatti+clipping+agoston                      *
 *                                                                             *
 * See also:                                                                   *
 * "Polygon Offsetting by Computing Winding Numbers"                           *
 * Paper no. DETC2005-85513 pp. 565-575                                        *
 * ASME 2005 International Design Engineering Technical Conferences            *
 * and Computers and Information in Engineering Conference (IDETC/CIE2005)     *
 * September 24-28, 2005 , Long Beach, California, USA                         *
 * http://www.me.berkeley.edu/~mcmains/pubs/DAC05OffsetPolygon.pdf             *
 *                                                                             *
 ******************************************************************************/

#pragma once

#include "IntPoint.h"


namespace ClipperLib {
  struct OutPt {
    int      idx;
    IntPoint pt;
    OutPt    *next;
    OutPt    *prev;

    void Dispose();

    bool PointIsVertex(const IntPoint &pt) const;
    bool PointOnPolygon(const IntPoint pt, bool UseFullInt64Range) const;
    bool PointInPolygon(const IntPoint &pt, bool UseFullInt64Range) const;
    void ReversePolyPtLinks();
    bool FirstIsBottomPt(const OutPt *btmPt2) const;
    OutPt *GetBottomPt();
    OutPt *FindSegment(bool UseFullInt64Range, IntPoint &pt1, IntPoint &pt2);
    OutPt *InsertPolyPtBetween(OutPt *p2, const IntPoint pt);
    int PointCount() const;
    bool Contains(const OutPt *outPt2, bool UseFullInt64Range) const;
  };
}
