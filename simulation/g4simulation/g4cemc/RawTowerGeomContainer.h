#ifndef NEWGEOMCONTAINER_H__
#define NEWGEOMCONTAINER_H__

#include "RawTowerDefs.h"
#include <phool/PHObject.h>
#include <phool/phool.h>
#include <iostream>
#include <map>

class RawTowerGeom;

class RawTowerGeomContainer : public PHObject
{

 public:

  typedef std::map<RawTowerDefs::keytype ,RawTowerGeom *> Map;
  typedef Map::iterator Iterator;
  typedef Map::const_iterator ConstIterator;
  typedef std::pair<Iterator, Iterator> Range;
  typedef std::pair<ConstIterator, ConstIterator> ConstRange;

  //! default constructor for ROOT IO
  virtual ~RawTowerGeomContainer() {}

  void identify(std::ostream& os=std::cout) const;

  virtual void set_calorimeter_id( RawTowerDefs::CalorimeterId  ) { PHOOL_VIRTUAL_WARN("set_calorimeter_id()");}
  virtual RawTowerDefs::CalorimeterId get_calorimeter_id( ) const { PHOOL_VIRTUAL_WARN("get_calorimeter_id()");return RawTowerDefs::NONE; }

  virtual ConstIterator add_tower_geometry(RawTowerGeom *geo) {PHOOL_VIRTUAL_WARN("add_tower_geometry()");}
  virtual RawTowerGeom *get_tower_geometry(RawTowerDefs::keytype key) {PHOOL_VIRTUAL_WARN("get_tower_geometry()");return NULL;}

  //! return all tower geometries
  virtual ConstRange get_tower_geometries( void ) const {PHOOL_VIRTUAL_WARN("get_tower_geometries()");return ConstRange(Map().begin(), Map().end()); };
  virtual Range get_tower_geometries( void ) {PHOOL_VIRTUAL_WARN("get_tower_geometries()");return Range(Map().begin(), Map().end()); };

  virtual unsigned int size() const {PHOOL_VIRTUAL_WARN("size()"); return 0;}

  // for cylindrical calorimeter only as implemented in RawTowerGeomContainer_Cylinderv1
  virtual double get_radius() const {PHOOL_VIRTUAL_WARN("get_radius()"); return NAN;}
  virtual double get_thickness() const  {PHOOL_VIRTUAL_WARN("get_thickness()"); return NAN;}
  virtual int get_phibins() const{PHOOL_VIRTUAL_WARN("get_phibins()"); return -1;}
  virtual double get_phistep() const {PHOOL_VIRTUAL_WARN("get_phistep()"); return NAN;}
  virtual double get_phimin() const {PHOOL_VIRTUAL_WARN("get_phimin()"); return NAN;}
  virtual int get_etabins() const {PHOOL_VIRTUAL_WARN("get_etabins()"); return -1;}
  virtual double get_etastep() const {PHOOL_VIRTUAL_WARN("get_etastep()"); return NAN;}
  virtual double get_etamin() const {PHOOL_VIRTUAL_WARN("get_etamin()"); return NAN;}

  virtual std::pair<double, double> get_phibounds(const int ibin) const {PHOOL_VIRTUAL_WARN("get_phibounds(const int)"); return std::make_pair(NAN,NAN);}
  virtual std::pair<double, double> get_etabounds(const int ibin) const {PHOOL_VIRTUAL_WARN("get_etabounds(const int)"); return std::make_pair(NAN,NAN);}
  virtual double get_etacenter(const int ibin) const {PHOOL_VIRTUAL_WARN("get_etacenter(const int)"); return NAN;}
  virtual double get_phicenter(const int ibin) const {PHOOL_VIRTUAL_WARN("get_phicenter(const int)"); return NAN;}

  virtual int get_etabin(const double eta) const {PHOOL_VIRTUAL_WARN("get_etabin(const double)"); return -1;}
  virtual int get_phibin(const double phi) const {PHOOL_VIRTUAL_WARN("get_phibin(const double)"); return -1;}

  virtual void set_radius(const double r) {PHOOL_VIRTUAL_WARN("set_radius(const double)");}
  virtual void set_thickness(const double t) {PHOOL_VIRTUAL_WARN("set_thickness(const double)");}
  virtual void set_phibins(const int i) {PHOOL_VIRTUAL_WARN("set_phibins(const int)");}
  virtual void set_phistep(const double phi) {PHOOL_VIRTUAL_WARN("set_phistep(const double)");}
  virtual void set_phimin(const double phi) {PHOOL_VIRTUAL_WARN("set_phimin(const double)");}
  virtual void set_etabins(const int i) {PHOOL_VIRTUAL_WARN("set_etabins(const int)");}
  virtual void set_etamin(const double z) {PHOOL_VIRTUAL_WARN("set_etamin(const double)");}
  virtual void set_etastep(const double z) {PHOOL_VIRTUAL_WARN("set_etastep(const double)");}
  virtual void set_etabounds(const int ibin, const std::pair<double, double> & bounds) {PHOOL_VIRTUAL_WARN("set_etabounds(const int ibin, const std::pair<double, double> & bounds)");}


 protected:
  //! this class is not for use. Base class only
  RawTowerGeomContainer() {}

  ClassDef(RawTowerGeomContainer,2)
};

#endif /* NEWGEOMCONTAINER_H__ */
