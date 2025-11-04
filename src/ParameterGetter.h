/*
* This file and associated .cpp file are licensed under the GPLv3 License Copyright (c) 2024 Sam Groveman
*
* Contributors: Sam Groveman
*/

#pragma once
#include <Arduino.h>
#include <SensorManager.h>
#include <vector>
#include <ArduinoJson.h>
#include <map>

/// @brief Allows for retrieval of a particular set of parameters' values
class ParameterGetter {
	public:
		/// @brief A set of sensor names and parameters names to use 
		std::vector<std::pair<String, String>> Parameters;

		std::map<String, std::map<String, double>> getParameterValues();
		std::map<String, std::vector<String>> listAllParameters();
};