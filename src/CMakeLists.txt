cmake_minimum_required(VERSION 3.8)
project(SMTPlan CXX)


set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(SMTPLAN_DIR ${SOURCE_DIR}/SMTPlan)
set(VALFILES_DIR ${SOURCE_DIR}/VALfiles)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_LIST_DIR}/cmake_modules)

find_package(GMP REQUIRED)
message(STATUS "GMP library found.")
message(STATUS "GMP include dir is: ${GMP_INCLUDE_DIR}")
message(STATUS "GMP library is: ${GMP_LIBRARIES}")
find_package(MPFR REQUIRED)
message(STATUS "MPFR library found.")
message(STATUS "MPFR include dir is: ${MPFR_INCLUDE_DIR}")
message(STATUS "MPFR library is: ${MPFR_LIBRARIES}")


file(GLOB MAIN_SOURCE_FILES ${SOURCE_DIR}/SMTPlan.cpp)
file(GLOB SMTPLAN_SOURCE_FILES ${SMTPLAN_DIR}/*.cpp)
file(GLOB VALFILES_SOURCES_FILES
	${VALFILES_DIR}/DebugWriteController.cpp
	${VALFILES_DIR}/Environment.cpp
	${VALFILES_DIR}/FastEnvironment.cpp
	${VALFILES_DIR}/FuncAnalysis.cpp
	${VALFILES_DIR}/SimpleEval.cpp
	${VALFILES_DIR}/TIM.cpp
	${VALFILES_DIR}/TimSupport.cpp
	${VALFILES_DIR}/TypedAnalyser.cpp
	${VALFILES_DIR}/instantiation.cpp
	${VALFILES_DIR}/pddl+.cpp
	${VALFILES_DIR}/ptree.cpp
	${VALFILES_DIR}/typecheck.cpp
)

add_executable(${PROJECT_NAME} ${MAIN_SOURCE_FILES} ${SMTPLAN_SOURCE_FILES} ${VALFILES_SOURCES_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR} ${GMP_INCLUDE_DIR} ${MPFR_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} z3 ${GMP_LIBRARIES} ${MPFR_LIBRARIES} pthread)