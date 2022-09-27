# CoalStar-GetHeight
## Part of the process by which the engine calculates terrain height at a given planar position. 

The process by which height values are obtained is to interpolate between svaed height entries and performing a slope interception calculation on the result. The height data within each chunk only contains the heights of each even entry, with the odd entries interpolated from the surrounding even heights.

Code within is covered by the Zlib license.