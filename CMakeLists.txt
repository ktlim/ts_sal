cmake_minimum_required (VERSION 3.12)
project (ts_sal)

set (TS_SAL_VERSION "" CACHE STRING "Version number of lsst_ts_sal RPM")
set (TS_SAL_RELEASE 1 CACHE STRING "Release number of lsst_ts_sal RPM")
set (Rpm_topdir ${CMAKE_BINARY_DIR}/rpmbuild)

if (TS_SAL_VERSION AND TS_SAL_RELEASE)
  set (Spec_file lsst_ts_sal-${TS_SAL_VERSION}-${TS_SAL_RELEASE}.spec)
  set (Rpm_file ${Rpm_topdir}/RPMS/noarch/lsst_ts_sal-${TS_SAL_VERSION}-${TS_SAL_RELEASE}.noarch.rpm)
  add_custom_command (
    OUTPUT ${Rpm_file}
# Use a second cmake script to fill out the spec template
    COMMAND ${CMAKE_COMMAND} -D Spec_SOURCE_DIR="${CMAKE_SOURCE_DIR}" -D Spec_BINARY_DIR="${CMAKE_BINARY_DIR}" -D TS_SAL_VERSION=${TS_SAL_VERSION} -D TS_SAL_RELEASE=${TS_SAL_RELEASE} -P ${CMAKE_SOURCE_DIR}/configure_spec.cmake
# Make the rpmbuild directories
    COMMAND $(CMAKE_COMMAND) -E make_directory ${Rpm_topdir}/BUILD ${Rpm_topdir}/BUILDROOT ${Rpm_topdir}/RPMS ${Rpm_topdir}/SOURCES ${Rpm_topdir}/SPECS ${Rpm_topdir}/SRPMS
# Make the RPM source tarball from the git clone
    COMMAND tar --exclude ${CMAKE_SOURCE_DIR}/.git --exclude ${CMAKE_BINARY_DIR} -P --transform=s:${CMAKE_SOURCE_DIR}:lsst_ts_sal-${TS_SAL_VERSION}: -czf ${Rpm_topdir}/SOURCES/lsst_ts_sal-v${TS_SAL_VERSION}.tar.gz ${CMAKE_SOURCE_DIR}
# Copy in our custom source patches
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib64.patch ${Rpm_topdir}/SOURCES
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/salenv.patch ${Rpm_topdir}/SOURCES
# Now do the rpmbuild
    COMMAND rpmbuild -bb --define '_topdir ${Rpm_topdir}' "${Spec_file}"
    DEPENDS ${CMAKE_SOURCE_DIR}/lsst_ts_sal.spec-tmpl
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
  add_custom_target (rpm ALL DEPENDS ${Rpm_file})
elseif (NOT TS_SAL_VERSION)
  message(FATAL_ERROR "TS_SAL_VERSION must be specified")
elseif (NOT TS_SAL_RELEASE)
  message(FATAL_ERROR "TS_SAL_RELEASE must be specified")
endif ()
