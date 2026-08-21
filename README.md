# UnrealVoxelSim.Voxel.Api

Engine-independent contracts for the logical voxel coordinate space and opaque voxel fields.

A field maps each in-bounds `Position` to one `CellValue`. Fields are independently owned capabilities: a solid
domain, liquid domain, or another future domain receives only the reader, region-reader, and editor interfaces it
requires for its own field. There is no API for discovering every field at a position.

`CellValue` is an opaque 32-bit atom. Zero is the canonical empty value; nonzero meanings belong exclusively to the
domain that owns the field. The API does not know about materials, fluids, entities, rendering, persistence, ECS, or
Unreal Engine.

## Logical topology

Coordinates use signed 32-bit integers. `Region` is a minimum-inclusive, maximum-exclusive axis-aligned region.
The six face-neighbor offsets define the domain-neutral cubic lattice. Region transfer order is X first, then Y, then
Z. This is a stable transfer contract, not an indication of an implementation's memory layout.

## Capabilities

- `IBounds` exposes logical field bounds.
- `IReader` performs checked point reads.
- `IRegionReader` performs one coarse-grained read into caller-owned reusable storage.
- `IEditor` applies compare-and-set mutation batches atomically for recoverable validation failures.

Mutation batches reject out-of-bounds positions and duplicates before changing state. Conflicts report the original
mutation index and observed value. Interfaces are thread-affine unless an implementation explicitly documents a
stronger guarantee.

## Deliberate omissions

Chunks, pages, compression, allocation, storage revisions, dirty blocks, and physical traversal are not part of this
API. Callers express locality with logical regions. A separately justified, segregated partition contract may be
introduced later only if representative benchmarks show that region access is insufficient.
