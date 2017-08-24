FILE(REMOVE_RECURSE
  "/home/snake/Documents/catkin_ws/devel/lib/libspline_interpolation_lib.pdb"
  "/home/snake/Documents/catkin_ws/devel/lib/libspline_interpolation_lib.so"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/spline_interpolation_lib.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
