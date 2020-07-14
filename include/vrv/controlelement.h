/////////////////////////////////////////////////////////////////////////////
// Name:        controlelement.h
// Author:      Laurent Pugin
// Created:     2015
// Copyright (c) Authors and others. All rights reserved.
/////////////////////////////////////////////////////////////////////////////

#ifndef __VRV_CONTROL_ELEMENT_H__
#define __VRV_CONTROL_ELEMENT_H__

#include "atts_shared.h"
#include "devicecontextbase.h"
#include "facsimileinterface.h"
#include "floatingobject.h"
#include "linkinginterface.h"

namespace vrv {

//----------------------------------------------------------------------------
// ControlElement
//----------------------------------------------------------------------------

/**
 * This class represents elements appearing within a measure.
 * It is not an abstract class but should not be instanciated directly.
 */
class ControlElement : public FloatingObject, public FacsimileInterface, public LinkingInterface, public AttLabelled, public AttTyped {
public:
    /**
     * @name Constructors, destructors, reset methods
     * Reset method resets all attribute classes
     */
    ///@{
    ControlElement();
    ControlElement(const std::string &classid);
    virtual ~ControlElement();
    virtual void Reset();
    virtual ClassId GetClassId() const { return CONTROL_ELEMENT; }
    ///@}

    /**
     * @name Get and set the X and Y drawing position
     */
    ///@{
    virtual int GetDrawingX() const;
    virtual int GetDrawingY() const;
    ///@}

    /**
     * @name Getter to interfaces
     */
    ///@{
    virtual FacsimileInterface *GetFascimileInterface() { return dynamic_cast<FacsimileInterface *>(this); }
    virtual LinkingInterface *GetLinkingInterface() { return dynamic_cast<LinkingInterface *>(this); }
    ///@}

    /**
     * Check if the ControlElement has a Rend child and return its @halign equivalent (if any)
     */
    data_HORIZONTALALIGNMENT GetChildRendAlignment();

    //----------//
    // Functors //
    //----------//

    /**
     * See Object::AdjustXOverflow
     */
    virtual int AdjustXOverflow(FunctorParams *functorParams);

    /**
     * See Object::ResetDrawing
     */
    virtual int ResetDrawing(FunctorParams *functorParams);

private:
    //
public:
    //
private:
    //
};

} // namespace vrv

#endif
