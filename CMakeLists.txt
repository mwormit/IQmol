project(IQmol C CXX Fortran)
cmake_minimum_required(VERSION 2.8)

find_package(OpenGL REQUIRED)
find_package(Qt4 COMPONENTS QtCore QtGui QtNetwork QtOpenGL QtSql QtXml
    REQUIRED)
set(Boost_USE_STATIC_LIBS TRUE)
find_package(Boost COMPONENTS iostreams serialization REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

set(CMAKE_MODULE_PATH ${IQmol_SOURCE_DIR}/cmake)
find_package(OpenBabel2 REQUIRED)
find_package(QGLViewer REQUIRED)
find_package(OpenMesh REQUIRED)
find_package(LibSsh2 REQUIRED)
unset(CMAKE_MODULE_PATH)

include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS} ${QGLVIEWER_DEFINITIONS})
include_directories(${OPENBABEL2_INCLUDE_DIR} ${OPENMESH_INCLUDE_DIR}
    ${QGLVIEWER_INCLUDE_DIR} ${LIBSSH2_INCLUDE_DIR} ${Boost_INCLUDE_DIRS})

add_subdirectory(src)

include(InstallRequiredSystemLibraries)

set(CPACK_PACKAGE_NAME "IQmol")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "3")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "IQmol Molecular Viewer")
set(CPACK_PACKAGE_VENDOR "Andrew Gilbert")
set(CPACK_PACKAGE_CONTACT "Andrew Gilbert")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "dist")
set(CPACK_INSTALLED_DIRECTORIES "share" ".")
set(CPACK_STRIP_FILES "bin/IQmol;bin/QUI")
set(CPACK_SOURCE_STRIP_FILES "")
set(CPACK_PACKAGE_EXECUTABLES "bin/IQmol;bin/QUI")
if(APPLE)
    set(CPACK_GENERATOR "Bundle")
    set(CPACK_BUNDLE_NAME "IQmol")
    set(CPACK_BUNDLE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/src/resources/IQmol.icns")
    set(CPACK_BUNDLE_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/src/Info.plist")
else(APPLE)
    set(CPACK_GENERATOR "DEB")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS
        "libopenbabel4, libqglviewer-qt4-2, libssh2-1")
endif(APPLE)
include(CPack)

