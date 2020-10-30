file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")
add_library(${MultiStack} STATIC ${srcs} ${hdrs})