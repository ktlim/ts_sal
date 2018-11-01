import os
import importlib
import unittest
# import lsst.utils.tests


class TestImportingLibraries(unittest.TestCase):

    def testImporting(self):
        assert 5 == 5 

if __name__ == "__main__":
    # lsst.utils.tests.init()
    unittest.main()
