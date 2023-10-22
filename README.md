# Cube3D

## Definitions

- **DDA**:
</p>


## DDA

- **position**: Green dot in Image1
- **Direction vector**: (black line) A vector showing the direction the player is looking to
- **Camera plane vector**: (blue line) A vector, that represens the surface of the camera screen. ector, that is perpendicular (90 degrees) to the direction plane
- **(rayDir)**: *(red lines) The ray direction vectors are used by the DDA algorithm and are calculated like : pos + dir + (plane * distance on plane)
- **FOV**: The field of vision is in between the two outer most rays.

![Image1](assets/image/pos_dir_plane.png)

![delta_dist and side_dist](assets/image/delta_dist-side_dist.png)

</p>


## Game view:

- **Player rotation**: When the player rotates, the dir and the plane have to rotate as well, the rays will automatically rotate as well. For the rotation the vector needs to be multiplied with the rotation matrix

![Rotation Matrix](assets/image/rotation_matrix.png)



Next step:

- [X] init dda_struct with start pos, dir, and plane
