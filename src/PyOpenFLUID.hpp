#ifndef __PYOPENFLUID_HPP__
#define __PYOPENFLUID_HPP__

#include <Python.h>

/* boost.python */
#include <boost/python/dict.hpp>
#include <boost/python/tuple.hpp>
#include <boost/python/object.hpp>

/* openfluid */
#include <openfluid/base/IOListener.hpp>
#include <openfluid/fluidx/FluidXDescriptor.hpp>
#include <openfluid/fluidx/AdvancedFluidXDescriptor.hpp>


// used for parameter default value (python None)
const boost::python::object BOOST_NONE = boost::python::object();


// =====================================================================
// =====================================================================


class PyOpenFLUID
{
  public :


// =====================================================================
// =====================================================================


    PyOpenFLUID ();


// =====================================================================
// =====================================================================


    ~PyOpenFLUID ();


// =====================================================================
/* ----------------------  GENERAL FUNCTIONS  ----------------------- */


    PyObject* getVersion (PyObject* PyObSelf,
                          PyObject* InTuple,
                          PyObject* InDict);


// =====================================================================
// =====================================================================


    void addExtraSimulatorsPaths (boost::python::object Paths);


// =====================================================================
// =====================================================================


    void resetExtraSimulatorsPaths ();


// =====================================================================
// =====================================================================


    boost::python::object getExtraSimulatorsPaths ();


// =====================================================================
// =====================================================================


    void addExtraObserversPaths (boost::python::object Paths);


// =====================================================================
// =====================================================================


    void resetExtraObserversPaths ();


// =====================================================================
// =====================================================================


    boost::python::object getExtraObserversPaths ();


// =====================================================================
// =====================================================================


    void printSimulationInfo ();


// =====================================================================
/* ------------------------  MODEL FUNCTIONS  ----------------------- */


    boost::python::object getSimulatorParam (boost::python::object SimID,
                                             boost::python::object ParamName);


// =====================================================================
// =====================================================================


    void setSimulatorParam (boost::python::object SimID,
                            boost::python::object ParamName,
                            boost::python::object ParamValue);


// =====================================================================
// =====================================================================


    void removeSimulatorParam (boost::python::object SimID,
                              boost::python::object ParamName);


// =====================================================================
// =====================================================================


    boost::python::object getSimulatorParams (boost::python::object SimID);


// =====================================================================
// =====================================================================


    boost::python::object getGeneratorParam (boost::python::object UnitClass,
                                             boost::python::object VarName,
                                             boost::python::object ParamName);


// =====================================================================
// =====================================================================


    void setGeneratorParam (boost::python::object UnitClass,
                            boost::python::object VarName,
                            boost::python::object ParamName,
                            boost::python::object ParamValue);


// =====================================================================
// =====================================================================


    boost::python::object getModelGlobalParam (boost::python::object ParamName);


// =====================================================================
// =====================================================================


    void setModelGlobalParam (boost::python::object ParamName,
                              boost::python::object ParamValue);


// =====================================================================
// =====================================================================


    boost::python::object getModelGlobalParams ();


// =====================================================================
// =====================================================================


    void removeModelGlobalParam (boost::python::object ParamName);


// =====================================================================
// =====================================================================


    boost::python::object getModelItems ();


// =====================================================================
// =====================================================================


    void addSimulator (boost::python::object SimID);


// =====================================================================
// =====================================================================


    void removeSimulator (boost::python::object SimID);


// =====================================================================
// =====================================================================


    void clearModel ();


// =====================================================================
// =====================================================================


    boost::python::object getSimulatorsInModel ();


// =====================================================================
/* ---------------------  MONITORING FUNCTIONS  --------------------- */


    boost::python::object getObserverParam (boost::python::object ObsID,
                                            boost::python::object ParamName);


// =====================================================================
// =====================================================================


    void setObserverParam (boost::python::object ObsID,
                           boost::python::object ParamName,
                           boost::python::object ParamValue);


// =====================================================================
// =====================================================================


    void removeObserverParam (boost::python::object ObsID,
                              boost::python::object ParamName);


// =====================================================================
// =====================================================================


    boost::python::object getObserverParams (boost::python::object ObsID);


// =====================================================================
// =====================================================================


    void addObserver (boost::python::object ObsID);


// =====================================================================
// =====================================================================


    void removeObserver (boost::python::object ObsID);


// =====================================================================
// =====================================================================


    void clearMonitoring ();


// =====================================================================
// =====================================================================


    boost::python::object getObserversInMonitoring ();


// =====================================================================
// =====================================================================


    boost::python::object addCSVOutput (boost::python::object UnitClass,
                                        boost::python::object Vars,
                                        boost::python::object ListID);


// =====================================================================
/* -------------------  SPATIAL DOMAIN FUNCTIONS  ------------------- */


    boost::python::object getUnitsClasses ();


// =====================================================================
// =====================================================================


    boost::python::object getUnitsIDs (boost::python::object UnitClass);


// =====================================================================
// =====================================================================


    void addUnit (boost::python::object UnitClass,
                  boost::python::object UnitID,
                  boost::python::object PcsOrder);


// =====================================================================
// =====================================================================


    void removeUnit (boost::python::object UnitClass,
                     boost::python::object UnitID);


// =====================================================================
// =====================================================================


    void clearAllUnits (boost::python::object UnitClass = BOOST_NONE);


// =====================================================================
// =====================================================================


    void setProcessOrder (boost::python::object UnitClass,
                          boost::python::object UnitID,
                          boost::python::object PcsOrder);


// =====================================================================
// =====================================================================


    boost::python::object getProcessOrder (boost::python::object UnitClass,
                                           boost::python::object UnitID);


// =====================================================================
// =====================================================================


    boost::python::object getUnitTos (boost::python::object UnitClass,
                                      boost::python::object UnitID);


// =====================================================================
// =====================================================================


    boost::python::object getUnitFroms (boost::python::object UnitClass,
                                        boost::python::object UnitID);


// =====================================================================
// =====================================================================


    void addFromToConnection (boost::python::object UnitClassFrom,
                              boost::python::object UnitIDFrom,
                              boost::python::object UnitClassTo,
                              boost::python::object UnitIDTo);


// =====================================================================
// =====================================================================


    void removeFromToConnection (boost::python::object UnitClassFrom,
                                 boost::python::object UnitIDFrom,
                                 boost::python::object UnitClassTo,
                                 boost::python::object UnitIDTo);


// =====================================================================
// =====================================================================


    boost::python::object getUnitChildren (boost::python::object UnitClass,
                                           boost::python::object UnitID);


// =====================================================================
// =====================================================================


    boost::python::object getUnitParents (boost::python::object UnitClass,
                                          boost::python::object UnitID);


// =====================================================================
// =====================================================================


    void addParentChildConnection (boost::python::object UnitClassParent,
                                   boost::python::object UnitIDParent,
                                   boost::python::object UnitClassChild,
                                   boost::python::object UnitIDChild);


// =====================================================================
// =====================================================================


    void removeParentChildConnection (boost::python::object UnitClassParent,
                                      boost::python::object UnitIDParent,
                                      boost::python::object UnitClassChild,
                                      boost::python::object UnitIDChild);


// =====================================================================
// =====================================================================


    void createAttribute (boost::python::object UnitClass,
                          boost::python::object AttrName,
                          boost::python::object AttrVal);


// =====================================================================
// =====================================================================


    boost::python::object getAttribute (boost::python::object UnitClass,
                                        boost::python::object UnitID,
                                        boost::python::object AttrName);

// =====================================================================
// =====================================================================


    void setAttribute (boost::python::object UnitClass,
                       boost::python::object UnitID,
                       boost::python::object AttrName,
                       boost::python::object AttrValue);


// =====================================================================
// =====================================================================


    void removeAttribute (boost::python::object UnitClass,
                          boost::python::object AttrName);


// =====================================================================
/* --------------------  INPUT OUTPUT FUNCTIONS  -------------------- */


    void openDataset (boost::python::object Path);


// =====================================================================
// =====================================================================


    void saveDataset (boost::python::object Path);


// =====================================================================
// =====================================================================


    void openProject (boost::python::object Path);


// =====================================================================
// =====================================================================


    PyObject* saveProject (PyObject* PyObSelf, PyObject* InTuple,
                           PyObject* InDict);


// =====================================================================
// =====================================================================


    void setCurrentOutputDir (boost::python::object Path);


// =====================================================================
// =====================================================================


    boost::python::object getCurrentOutputDir ();


// =====================================================================
/* ---------------------  SIMULATION FUNCTIONS  --------------------- */


    boost::python::object getDefaultDeltaT ();


// =====================================================================
// =====================================================================


    void setDefaultDeltaT (boost::python::object DefaultDeltaT);


// =====================================================================
// =====================================================================


    boost::python::object getPeriodBeginDate ();


// =====================================================================
// =====================================================================


    boost::python::object getPeriodEndDate ();


// =====================================================================
// =====================================================================


    void setPeriodBeginDate (boost::python::object BDate);


// =====================================================================
// =====================================================================


    void setPeriodEndDate (boost::python::object EDate);


// =====================================================================
// =====================================================================


    void runProject (boost::python::object Path);


// =====================================================================
// =====================================================================


    boost::python::object runSimulation ();


// =====================================================================
// =====================================================================


    void updateOutputsConfig ();


// =====================================================================
/* ------------------------ PYTHON FUNCTIONS  ----------------------- */


    boost::python::object getStr ();


// =====================================================================
/* ------------------------ SPECIAL FUNCTIONS  ---------------------- */


    void initWithoutDescriptor ();


// =====================================================================
// =====================================================================


    void initFluidxDescriptor ();


// =====================================================================
// =====================================================================


    void initAdvancedFluidxDescriptor ();


// =====================================================================
// =====================================================================


  private :
    /* basics */
    openfluid::base::IOListener* mp_IOL;
    openfluid::fluidx::FluidXDescriptor* mp_FXDesc;
    openfluid::fluidx::AdvancedFluidXDescriptor* mp_AdvFXDesc;

    /* last observer id */
    unsigned int m_LastObsID;

};


// =====================================================================
/* ----------------------- STATIC FUNCTIONS  ------------------------ */


void setPyOFCSVFormat (openfluid::fluidx::ObserverDescriptor& Observer);


#endif // __PYOPENFLUID_HPP__
