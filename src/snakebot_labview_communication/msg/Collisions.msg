# Collision data as given by the snakebot_collisions node.
# Can also be used to send data from snakebot_pushpoints

# Message formatted for easier extraction of data on LabVIEW side

float64[] position_x
float64[] position_y
float64[] position_z

int32[] link_numbers

string[] contact_sides

float64[] normal_x
float64[] normal_y
float64[] normal_z

float64[] tangent_x
float64[] tangent_y
float64[] tangent_z

float64[] force_x
float64[] force_y
float64[] force_z
