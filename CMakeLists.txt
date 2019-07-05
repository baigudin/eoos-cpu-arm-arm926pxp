# EOOS RT CPU ARM ARM926EJ-S Development Chip.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2019, Sergey Baigudin, Embedded Team
# @license   http://embedded.team/license/

enable_language(CXX)

target_include_directories(${PROJECT_NAME}
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

target_sources(${PROJECT_NAME}
PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Allocator.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Boot.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Cpu.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Interrupt.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Object.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Pll.cpp
    ${CMAKE_CURRENT_LIST_DIR}/source/cpu.Timer.cpp
)
