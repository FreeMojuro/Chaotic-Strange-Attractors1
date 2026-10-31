#pragma once
#include <raylib.h>
#include <vector>



inline constexpr int window_width{1200};
inline constexpr int window_height{900};
inline constexpr float dt{0.01};
inline constexpr float scale{1};

inline float P{10};
inline float B{8.0/3.0};
inline float R{28};
inline int substeps{2};
inline bool isdragging{false};
inline float cameraPitch{0.8f};

inline std::vector<Vector3> positions;
inline Vector3 currentpos{0.01f, 0.5f, 0.05f};

std::vector<Vector3> preset1(); // the Lorenz attractor
std::vector<Vector3> preset2(); // the Finance attractor


void reset();
