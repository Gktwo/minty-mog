#pragma once

#define IMGUI_DEFINE_MATH_OPERATORS
#include <Windows.h>

#include "../GUI/GuiDefinitions.h"
#include "../api/imgui/ImGui/imgui.h"
#include "../api/imgui/ImGui/imgui_internal.h"
#include "../api/imgui/ImGui/imgui_stdlib.h"
//#include "Utils.hpp"
#include "../config/ConfigManager.h"
#include "Logger.h"

void HelpMarker(const char* desc);

#define END_WIDGET() \
    if (description != nullptr) { \
        ImGui::SameLine(); \
        HelpMarker(description); \
    }

template <typename T>
bool ConfigCheckbox(const char* name, ConfigField<T>& field, const char* description = nullptr) {
    T& value = field.getValue();

    if (ImGui::Checkbox(name, &value)) {
        field.setValue(value);
        config::setValue(field, value);
	return value;
    }
    END_WIDGET();
    return false;
}

bool BeginGroupPanel(const char* label, bool node = false, const ImVec2& size = ImVec2(-1.0f, 0.0f));
void EndGroupPanel();


template <typename T>
bool ConfigInputText(const char* name, ConfigField<T>& field, const char* description = nullptr) {
    T& value = field.getValue();

    if (ImGui::InputText(name, &value)) {
        field.setValue(value);
        config::setValue(field, value);
	return true;
    }
    END_WIDGET();
    return false;
}

template <typename T>
bool ConfigSliderInt(const char* name, ConfigField<T>& field, const int min, const int max, const char* description = nullptr) {
    T& value = field.getValue();

    if (ImGui::SliderInt(name, &value, min, max)) {
        field.setValue(value);
        config::setValue(field, value);
	return true;
    }
    END_WIDGET();
    return false;
}

template <typename T>
bool ConfigDragInt(const char* name, ConfigField<T>& field, const int step, const int min, const int max, const char* description = nullptr) {
    T& value = field.getValue();

    if (ImGui::DragInt(name, &value, (float) step, min, max, nullptr, ImGuiSliderFlags_AlwaysClamp)) {
        field.setValue(value);
        config::setValue(field, value);
	return true;
    }
    END_WIDGET();
    return false;
}

template <typename T>
bool ConfigSliderFloat(const char* name, ConfigField<T>& field, const float min, const float max, const char* description = nullptr) {
    T& value = field.getValue();

    if (ImGui::SliderFloat(name, &value, min, max)) {
        field.setValue(value);
        config::setValue(field, value);
	return true;
    }
    END_WIDGET();
    return false;
}


void ConfigComboLanguage(ConfigField<int>& f_Language);


void AddUnderLine(ImColor col_);
void TextURL(const char* name_, const char* URL_, bool SameLineBefore_, bool SameLineAfter_);
