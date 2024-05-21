# computer-graphics
## Projects at CS184 (UC Berkeley) and other related computer graphics
### Step 1: [Transformation](1.Transformation/)
Transform a model from eye view to screen:
$$ModelViewProject = Project · Viewr_R · Viewr_T · Model_S · Model_R · Model_T$$

Model Translation **T**, Model Scaling **S**, Model Rotation **R**, View Translation, View Rotation

### Step 2: [Rasterization](2.Rasterization/)
Rasterization is the process of converting a 3D model into a 2D image on a computer screen.
- Draw a single color triangles
  - *rasterize_triangle* in *rasterize.cpp*
- Antialiasing
  - Use supersampling to antialias your triangles. The sample_rate parameter in DrawRend
(adjusted using the − and = keys) tells you how many samples to use per pixel.

- Transforms
  - translate, scale, rotate
- Barycentric coordinate 
  - *RasterizerImp :: rasterize_interpolated_color_triangle(...)* draw a triangle with colors defined at the vertices and interpolated across the triangle area using barycentric interpolation
- Texture mapping 
  - *RasterizerImp :: rasterize_texturedtriangle(...)* draw a triangle with colors defined by texture mapping with the given 2D texture coordinates at each vertex and the given Texture image
- Mipmapping
  - *RasterizerImp :: rasterize_textured_triangle(...)* support sampling different mipmap levels (M ipLevel S). The GUI toggles RasterizerImp’s LevelSampleMethod variable lsm using the L key.



### Step 3: [Geometry](3.Geometry_Modeling/)
Geometry is the process of modeling and representing 3D objects in a computer graphics application.

- Part I: Bezier Curves and Surfaces
    - Bezier curves with 1D de Casteljau subdivision 
    - Bezier surfaces with separable 1D de Casteljau 
- Part II: Bezier Curves and Surfaces 
  - Area-weighted vertex normals 
  - Edge flip 
  - Edge split 
  - Loop subdivision for mesh upsampling 
- More GUI sees description file[3.Geometry/description.pdf]

### Step 4: Ray Tracing
Ray Tracing is a method for computing the color of a pixel on a computer screen by tracing a ray through the scene and computing the color of the surface that the ray intersects.
- [Ray Tracing I](4.Ray_TracingI/)
    - Part 1: Ray Generation and Scene Intersection 
    - Part 2: Bounding Volume Hierarchy 
    - Part 3: Direct Illumination 
    - Part 4: Global Illumination 
    - Part 5: Adaptive Sampling
- [Ray Tracing II](5.Ray_TracingII/)
    - Mirror and Glass Materials 
    - Microfacet Material 
    - Environment Light 
    - Depth of Field
- Details about [Ray Tracing I](4.Ray_TracingI/report.pdf) and [Ray Tracing II](5.Ray_TracingII/report.pdf). Results Showcase [Ray Tracing I](4.Ray_TracingI/result) and [Ray Tracing II](5.Ray_TracingII/image).


## [From point to cloud](point_to_cloud/README.md)
- Description

    Based on projects at UC Berkeley, we can convert point clouds into 3D meshes. Specifically, given an
input file of format .plz/.ply, our program will output a 3D triangle mesh in the format .dae.
The purpose of a 3D scanner/Depth camera is to analyze a real-world object and collect data on
the object’s shape and appearance. Devices nowadays commonly scan the surface of the object and output data in the form of
point clouds. Then the point clouds must be processed to created a 3D virtual mesh. 
I constructed a point cloud processing method that connects the points within the point
cloud to create a mesh. The main references for this project are this paper on the [ball-pivoting
algorithm](https://ieeexplore.ieee.org/document/817351) , and this paper on [Poisson surface reconstruction](https://hhoppe.com/poissonrecon.pdf).

- Deliverables

    To create a mesh reconstruction from a point cloud, I implemented "The Ball-Pivoting
Algorithm for Surface Reconstruction algorithm" by using the HalfEdge data structure. Essentially,
this algorithm will give us a function that converts from .xyz to .dae. I compared the performance between the two algorithms, including timing the system on specific 3D scanned files. For a file input, we want the algorithm to have fast mesh creation but at the same time be accurate. A precise metric would be the number of FLOPs required by each algorithm. You can use a timer (for simplicity) between the start of the
mesh creation and the end using different algorithms (either the basic implementation or modified implementations of the basic one) to see which ones obtain the fastest runtime. There are some relatively advanced statistical calculations for judging mesh accuracy for accuracy. The lecture on geometry processing gives a good basis for determining the “goodness” of a mesh rendering. For test cases, I use [RPly](https://w3.impa.br/~diego/software/rply/)
