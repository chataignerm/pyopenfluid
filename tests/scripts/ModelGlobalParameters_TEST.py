#!/bin/env/python
# -*- coding: UTF-8 -*-

from BaseTest import *

class PyOpenFLUIDTest_ModelGlobalParameter(PyOpenFLUIDTest):

    def runTest(self):
        """Test of model global parameters functions."""
        self.assertRaises(TypeError, self.openfluid.getModelGlobalParam, 65)
        self.assertRaises(TypeError, self.openfluid.getModelGlobalParam, None)
        self.assertRaises(TypeError, self.openfluid.setModelGlobalParam, "b", 9)
        self.assertRaises(TypeError, self.openfluid.setModelGlobalParam, 9, "b")

        # tests on getModelGlobalParam/setModelGlobalParam
        ParamsList = (("test_bidon","vrai"),("gvalue","37.2"),("wind","60"),
                ("megabidon","??"))
        for ParamName, ParamValue in ParamsList:
            self.openfluid.setModelGlobalParam(ParamName, ParamValue)

            # test of memory access
            for i in range(15):
                # will crash if the memory isn't managed good enough
                Tmp = self.openfluid.getModelGlobalParam(ParamName)

            self.assertEquals(self.openfluid.getModelGlobalParam(ParamName), ParamValue)

        # tests on removeModelGlobalParam/getModelGlobalParams
        CheckList = map((lambda (a,b): a), ParamsList)
        self.assertTrue(isinstance(self.openfluid.getModelGlobalParams(), (tuple, list)))
        self.assertItemsEqual(CheckList, self.openfluid.getModelGlobalParams())

        self.openfluid.removeModelGlobalParam(ParamsList[0][0])
        self.assertIsNone(self.openfluid.getModelGlobalParam(ParamsList[0][0]))

        self.assertEquals(len(self.openfluid.getModelGlobalParams()), len(ParamsList)-1)

if __name__ == "__main__":
    unittest.main()
