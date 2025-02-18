// @(#)root/geom:$Id$
// Author: Mihaela Gheata   20/11/04

/*************************************************************************
 * Copyright (C) 1995-2000, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TGeoHype
#define ROOT_TGeoHype

#include "TGeoTube.h"

class TGeoHype : public TGeoTube {
protected:
   // data members inherited from TGeoTube:
   //   Double_t              fRmin; // inner radius at z=0
   //   Double_t              fRmax; // outer radius at z=0
   //   Double_t              fDz;   // half length
   Double_t fStIn;  // Stereo angle for inner surface
   Double_t fStOut; // Stereo angle for inner surface

private:
   // Precomputed parameters:
   Double_t fTin;    // Tangent of stereo angle for inner surface
   Double_t fTout;   // Tangent of stereo angle for outer surface
   Double_t fTinsq;  // Squared tangent of stereo angle for inner surface
   Double_t fToutsq; // Squared tangent of stereo angle for outer surface

   TGeoHype(const TGeoHype &) = delete;
   TGeoHype &operator=(const TGeoHype &) = delete;

public:
   // constructors
   TGeoHype();
   TGeoHype(Double_t rin, Double_t stin, Double_t rout, Double_t stout, Double_t dz);
   TGeoHype(const char *name, Double_t rin, Double_t stin, Double_t rout, Double_t stout, Double_t dz);
   TGeoHype(Double_t *params);
   // destructor
   ~TGeoHype() override;
   // methods

   Double_t Capacity() const override;
   void ComputeBBox() override;
   void ComputeNormal(const Double_t *point, const Double_t *dir, Double_t *norm) const override;
   void ComputeNormal_v(const Double_t *points, const Double_t *dirs, Double_t *norms, Int_t vecsize) override;
   Bool_t Contains(const Double_t *point) const override;
   void Contains_v(const Double_t *points, Bool_t *inside, Int_t vecsize) const override;
   Double_t DistFromInside(const Double_t *point, const Double_t *dir, Int_t iact = 1, Double_t step = TGeoShape::Big(),
                           Double_t *safe = nullptr) const override;
   void DistFromInside_v(const Double_t *points, const Double_t *dirs, Double_t *dists, Int_t vecsize,
                         Double_t *step) const override;
   Double_t DistFromOutside(const Double_t *point, const Double_t *dir, Int_t iact = 1,
                            Double_t step = TGeoShape::Big(), Double_t *safe = nullptr) const override;
   void DistFromOutside_v(const Double_t *points, const Double_t *dirs, Double_t *dists, Int_t vecsize,
                          Double_t *step) const override;
   Int_t DistToHype(const Double_t *point, const Double_t *dir, Double_t *s, Bool_t inner, Bool_t in) const;
   Int_t DistancetoPrimitive(Int_t px, Int_t py) override;
   TGeoVolume *
   Divide(TGeoVolume *voldiv, const char *divname, Int_t iaxis, Int_t ndiv, Double_t start, Double_t step) override;
   Double_t GetAxisRange(Int_t iaxis, Double_t &xlo, Double_t &xhi) const override;
   void GetBoundingCylinder(Double_t *param) const override;
   const TBuffer3D &GetBuffer3D(Int_t reqSections, Bool_t localFrame) const override;
   Int_t GetByteCount() const override { return 64; }
   Bool_t GetPointsOnSegments(Int_t /*npoints*/, Double_t * /*array*/) const override { return kFALSE; }
   TGeoShape *GetMakeRuntimeShape(TGeoShape *mother, TGeoMatrix *mat) const override;
   void GetMeshNumbers(Int_t &nvert, Int_t &nsegs, Int_t &npols) const override;
   Int_t GetNmeshVertices() const override;
   Double_t GetStIn() const { return fStIn; }
   Double_t GetStOut() const { return fStOut; }
   Bool_t HasInner() const { return !TestShapeBit(kGeoRSeg); }
   Double_t RadiusHypeSq(Double_t z, Bool_t inner) const;
   Double_t ZHypeSq(Double_t r, Bool_t inner) const;
   void InspectShape() const override;
   Bool_t IsCylType() const override { return kTRUE; }
   TBuffer3D *MakeBuffer3D() const override;
   // virtual void          Paint(Option_t *option);
   Double_t Safety(const Double_t *point, Bool_t in = kTRUE) const override;
   void Safety_v(const Double_t *points, const Bool_t *inside, Double_t *safe, Int_t vecsize) const override;
   Double_t SafetyToHype(const Double_t *point, Bool_t inner, Bool_t in) const;
   void SavePrimitive(std::ostream &out, Option_t *option = "") override;
   void SetHypeDimensions(Double_t rin, Double_t stin, Double_t rout, Double_t stout, Double_t dz);
   void SetDimensions(Double_t *param) override;
   void SetPoints(Double_t *points) const override;
   void SetPoints(Float_t *points) const override;
   void SetSegsAndPols(TBuffer3D &buff) const override;
   void Sizeof3D() const override;

   ClassDefOverride(TGeoHype, 1) // hyperboloid class
};

#endif
