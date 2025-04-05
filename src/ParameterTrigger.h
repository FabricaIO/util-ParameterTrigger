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

/// @brief Allows for retrieval of a particular set of parameters' value
class ParameterTrigger {
	public:
		/// @brief Holds parameter configuration
		struct {			
			/// @brief A set of sensor names and paramater names to use 
			std::vector<std::pair<String, String>> Parameters;

			/// @brief Whether to enable auto triggering or not
			bool Enabled;			
		} parameter_config;

		std::map<String, std::map<String, double>> getParameterValues();

		std::map<String, std::vector<String>> listAllParameters();
};