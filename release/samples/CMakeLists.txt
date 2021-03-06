

IF (WITH_SAMPLES)

  message("-- Building Samples")

include_directories(../src ${OPENSSL_INCLUDE_DIR} ${CPPUNIT_INCLUDE_DIR} ccommon cppcommon cgetasstruct cgetdoc cppgetdoc )

add_executable(getdoc
    cppgetdoc/getdoc.cpp
    cppcommon/ConnectionFactory.cpp
)
add_executable(cgetdoc
    cgetdoc/cgetdoc.c
    cppcommon/ConnectionFactory.cpp
    ccommon/ConnectionFactoryWrapper.cpp
)
add_executable(cgetasstruct
    cgetasstruct/cgetasstruct.c
    cppcommon/ConnectionFactory.cpp
    ccommon/ConnectionFactoryWrapper.cpp
    cgetasstruct/CStructWrapper.cpp
)
add_executable(cppproducer
    cppproducer/producermain.cpp
)
add_executable(cppbatchupload
    cppbatchupload/batchupload.cpp
    cppcommon/ConnectionFactory.cpp
)
add_executable(cppsearch
    cppsearch/search.cpp
    cppcommon/ConnectionFactory.cpp
)
target_link_libraries(getdoc mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cgetdoc mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cgetasstruct mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cppproducer mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cppbatchupload mlclient ${Casablanca_LIBRARIES})
target_link_libraries(cppsearch mlclient ${Casablanca_LIBRARIES})

else()
  message("-- NOT building Samples (edit ./bin/build-deps-settings.sh|bat with WITH_SAMPLES=1 to enable)")
endif()
