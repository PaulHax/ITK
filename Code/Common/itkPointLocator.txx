/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkPointLocator.txx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#include "itkPointLocator.h"

ITK_NAMESPACE_BEGIN

template <typename TPointIdentifier,typename TCoordRep,int VPointDimension>
PointLocator<TPointIdentifier,TCoordRep,VPointDimension>
::PointLocator():
Points(NULL)
{
  m_Divisions = new unsigned long [PointDimension];
}

template <typename TPointIdentifier,typename TCoordRep,int VPointDimension>
PointLocator<TPointIdentifier,TCoordRep,VPointDimension>
::~PointLocator()
{
  delete [] m_Divisions;
}

template <typename TPointIdentifier,typename TCoordRep,int VPointDimension>
void 
PointLocator<TPointIdentifier,TCoordRep,VPointDimension>
::InitPointInsertion(PointsContainer *newPts, 
                     CoordRep bounds[2*PointDimension])
{
  // Check the input
  m_Points = newPts;
#if 0
  if ( newPts )
    {
    this->Points = newPts;
    }
  else
    {
    //throw an exception and return
    return;
    }
#endif
}

template <typename TPointIdentifier,typename TCoordRep,int VPointDimension>
void 
PointLocator<TPointIdentifier,TCoordRep,VPointDimension>
::InitIncrementalPointInsertion(PointsContainer *newPts, 
                                CoordRep bounds[2*PointDimension])
{
  // Check the input
  m_Points = newPts;
#if 0
  if ( newPts )
    {
    this->Points = newPts;
    }
  else
    {
    //throw an exception and return
    return;
    }
#endif
}

#if 0
  int i;
  int maxDivs;
  typedef vtkIdList *vtkIdListPtr;
  float hmin;
  int ndivs[3];
  float level;

  if ( this->HashTable )
    {
    this->FreeSearchStructure();
    }
  if ( newPts == NULL )
    {
    vtkErrorMacro(<<"Must define points for point insertion");
    return 0;
    }
  if (this->Points != NULL)
    {
    this->Points->UnRegister(this);
    }
  this->Points = newPts;
  this->Points->Register(this);

  for (i=0; i<3; i++)
    {
    this->Bounds[2*i] = bounds[2*i];
    this->Bounds[2*i+1] = bounds[2*i+1];
    if ( this->Bounds[2*i+1] <= this->Bounds[2*i] )
      {
      this->Bounds[2*i+1] = this->Bounds[2*i] + 1.0;
      }
    }

  if ( this->Automatic && (estNumPts > 0) )
    {
    level = (float) estNumPts / this->NumberOfPointsPerBucket;
    level = ceil( pow((double)level,(double)0.33333333) );
    for (i=0; i<3; i++)
      {
      ndivs[i] = (int) level;
      }
    } 
  else 
    {
    for (i=0; i<3; i++)
      {
      ndivs[i] = (int) this->Divisions[i];
      }
    }

  for (i=0; i<3; i++) 
    {
    ndivs[i] = (ndivs[i] > 0 ? ndivs[i] : 1);
    this->Divisions[i] = ndivs[i];
    }

  this->NumberOfBuckets = ndivs[0]*ndivs[1]*ndivs[2];
  this->HashTable = new vtkIdListPtr[this->NumberOfBuckets];
  memset (this->HashTable, 0, this->NumberOfBuckets*
          sizeof(vtkIdListPtr));
  //
  //  Compute width of bucket in three directions
  //
  for (i=0; i<3; i++) 
    {
    this->H[i] = (this->Bounds[2*i+1] - this->Bounds[2*i]) / ndivs[i] ;
    }

  this->InsertionTol2 = this->Tolerance * this->Tolerance;

  for (maxDivs=0, hmin=VTK_LARGE_FLOAT, i=0; i<3; i++) 
    {
    hmin = (this->H[i] < hmin ? this->H[i] : hmin);
    maxDivs = (maxDivs > this->Divisions[i] ? maxDivs : this->Divisions[i]);
    }
  this->InsertionLevel = ceil ((double) this->Tolerance / hmin);
  this->InsertionLevel = (this->InsertionLevel > maxDivs ? maxDivs : this->InsertionLevel);
  return 1;
#endif


ITK_NAMESPACE_END
