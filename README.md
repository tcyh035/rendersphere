# rendersphere

mkdir build
cd build
cmake ..
cmake --build .

基于RayCast渲染一个球，暂时只实现了Blinn-phong model。在windows/ubuntu24.04中测试通过
使用方法：rendersphere [outputFileName]
不写文件名的话默认output.ppm

参考资料包括：
https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays.html

games101

Fundamentals of Computer Graphics

使用了Eigen库来进行矩阵运算。