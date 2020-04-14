CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_REQUIRED_STANDARD ON)
SET(CMAKE_DEBUG_POSTFIX "-d")

SET(PROJECT_NAME "sfui")
PROJECT(${PROJECT_NAME} LANGUAGES CXX)

SET(HEADERS Utils/Arrow.hpp Utils/Box.hpp Button.hpp CheckBox.hpp ComboBox.hpp Utils/Cross.hpp Layouts/FormLayout.hpp Layouts/HorizontalBoxLayout.hpp Image.hpp InputBox.hpp Utils/ItemBox.hpp Label.hpp Layouts/Layout.hpp Layouts/Menu.hpp MultilineInputBox.hpp OptionsBox.hpp ProgressBar.hpp SFUI.hpp Slider.hpp SpriteButton.hpp Theme.hpp Layouts/VerticalBoxLayout.hpp Widget.hpp)
SET(SOURCES Utils/Arrow.cpp Utils/Box.cpp Button.cpp CheckBox.cpp ComboBox.inl Utils/Cross.cpp Layouts/FormLayout.cpp Layouts/HorizontalBoxLayout.cpp Image.cpp InputBox.cpp Utils/ItemBox.inl Label.cpp Layouts/Layout.cpp Layouts/Menu.cpp MultilineInputBox.cpp OptionsBox.inl ProgressBar.cpp SFUI.cpp Slider.cpp SpriteButton.cpp Theme.cpp Layouts/VerticalBoxLayout.cpp Widget.cpp)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ../SFML/include)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} sfml-graphics sfml-audio sfml-window sfml-system)

if (UNIX)
	TARGET_LINK_LIBRARIES(${PROJECT_NAME} GL)
endif (UNIX)

