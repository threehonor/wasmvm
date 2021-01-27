/* (c) 2019 Confio UO. Licensed under Apache-2.0 */

/* Generated with cbindgen:0.14.3 */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

enum ErrnoValue {
  ErrnoValue_Success = 0,
  ErrnoValue_Other = 1,
  ErrnoValue_OutOfGas = 2,
};
typedef int32_t ErrnoValue;

/**
 * This enum gives names to the status codes returned from Go callbacks to Rust.
 *
 * The go code will return one of these variants when returning.
 *
 */
enum GoResult {
  GoResult_Ok = 0,
  /**
   * Go panicked for an unexpected reason.
   */
  GoResult_Panic = 1,
  /**
   * Go received a bad argument from Rust
   */
  GoResult_BadArgument = 2,
  /**
   * Ran out of gas while using the SDK (e.g. storage)
   */
  GoResult_OutOfGas = 3,
  /**
   * An error happened during normal operation of a Go callback, which should abort the contract
   */
  GoResult_Other = 4,
  /**
   * An error happened during normal operation of a Go callback, which should be fed back to the contract
   */
  GoResult_User = 5,
};
typedef int32_t GoResult;

typedef struct AnalysisReport {
  bool has_ibc_entry_points;
} AnalysisReport;

typedef struct cache_t {

} cache_t;

/**
 * A view into an externally owned byte slice (Go `[]byte`).
 * Use this for the current call only. A view cannot be copied for safety reasons.
 * If you need a copy, use [`to_owned`].
 *
 * Go's nil value is fully supported, such that we can differentiate between nil and an empty slice.
 */
typedef struct ByteSliceView {
  /**
   * True if and only if the byte slice is nil in Go. If this is true, the other fields must be ignored.
   */
  bool is_nil;
  const uint8_t *ptr;
  uintptr_t len;
} ByteSliceView;

/**
 * An optional Vector type that requires explicit creation and destruction
 * and can be sent via FFI.
 * It can be created from `Option<Vec<u8>>` and be converted into `Option<Vec<u8>>`.
 *
 * This type is always created in Rust and always dropped in Rust.
 * If Go code want to create it, it must instruct Rust to do so via the
 * `new_unmanaged_vector` FFI export. If Go code wants to consume its data,
 * it must create a copy and instruct Rust to destroy it via the
 * `destroy_unmanaged_vector` FFI export.
 */
typedef struct UnmanagedVector {
  /**
   * True if and only if this is None/nil. If this is true, the other fields must be ignored.
   */
  bool is_nil;
  uint8_t *ptr;
  uintptr_t len;
  uintptr_t cap;
} UnmanagedVector;

/**
 * An opaque type. `*gas_meter_t` represents a pointer to Go memory holding the gas meter.
 */
typedef struct gas_meter_t {
  uint8_t _private[0];
} gas_meter_t;

typedef struct db_t {
  uint8_t _private[0];
} db_t;

/**
 * A view into a `Option<&[u8]>`, created and maintained by Rust.
 *
 * This can be copied into a []byte in Go.
 */
typedef struct U8SliceView {
  /**
   * True if and only if this is None. If this is true, the other fields must be ignored.
   */
  bool is_none;
  const uint8_t *ptr;
  uintptr_t len;
} U8SliceView;

typedef struct iterator_t {
  uint64_t db_counter;
  uint64_t iterator_index;
} iterator_t;

typedef struct Iterator_vtable {
  int32_t (*next_db)(iterator_t, gas_meter_t*, uint64_t*, UnmanagedVector*, UnmanagedVector*, UnmanagedVector*);
} Iterator_vtable;

typedef struct GoIter {
  gas_meter_t *gas_meter;
  iterator_t state;
  Iterator_vtable vtable;
} GoIter;

typedef struct DB_vtable {
  int32_t (*read_db)(db_t*, gas_meter_t*, uint64_t*, U8SliceView, UnmanagedVector*, UnmanagedVector*);
  int32_t (*write_db)(db_t*, gas_meter_t*, uint64_t*, U8SliceView, U8SliceView, UnmanagedVector*);
  int32_t (*remove_db)(db_t*, gas_meter_t*, uint64_t*, U8SliceView, UnmanagedVector*);
  int32_t (*scan_db)(db_t*, gas_meter_t*, uint64_t*, U8SliceView, U8SliceView, int32_t, GoIter*, UnmanagedVector*);
} DB_vtable;

typedef struct DB {
  gas_meter_t *gas_meter;
  db_t *state;
  DB_vtable vtable;
} DB;

typedef struct api_t {
  uint8_t _private[0];
} api_t;

typedef struct GoApi_vtable {
  int32_t (*humanize_address)(const api_t*, U8SliceView, UnmanagedVector*, UnmanagedVector*, uint64_t*);
  int32_t (*canonicalize_address)(const api_t*, U8SliceView, UnmanagedVector*, UnmanagedVector*, uint64_t*);
} GoApi_vtable;

typedef struct GoApi {
  const api_t *state;
  GoApi_vtable vtable;
} GoApi;

typedef struct querier_t {
  uint8_t _private[0];
} querier_t;

typedef struct Querier_vtable {
  int32_t (*query_external)(const querier_t*, uint64_t, uint64_t*, U8SliceView, UnmanagedVector*, UnmanagedVector*);
} Querier_vtable;

typedef struct GoQuerier {
  const querier_t *state;
  Querier_vtable vtable;
} GoQuerier;

AnalysisReport analyze_code(cache_t *cache, ByteSliceView checksum, UnmanagedVector *error_msg);

void destroy_unmanaged_vector(UnmanagedVector v);

UnmanagedVector handle(cache_t *cache,
                       ByteSliceView checksum,
                       ByteSliceView env,
                       ByteSliceView info,
                       ByteSliceView msg,
                       DB db,
                       GoApi api,
                       GoQuerier querier,
                       uint64_t gas_limit,
                       bool print_debug,
                       uint64_t *gas_used,
                       UnmanagedVector *error_msg);

UnmanagedVector ibc_channel_close(cache_t *cache,
                                  ByteSliceView checksum,
                                  ByteSliceView env,
                                  ByteSliceView msg,
                                  DB db,
                                  GoApi api,
                                  GoQuerier querier,
                                  uint64_t gas_limit,
                                  bool print_debug,
                                  uint64_t *gas_used,
                                  UnmanagedVector *error_msg);

UnmanagedVector ibc_channel_connect(cache_t *cache,
                                    ByteSliceView checksum,
                                    ByteSliceView env,
                                    ByteSliceView msg,
                                    DB db,
                                    GoApi api,
                                    GoQuerier querier,
                                    uint64_t gas_limit,
                                    bool print_debug,
                                    uint64_t *gas_used,
                                    UnmanagedVector *error_msg);

UnmanagedVector ibc_channel_open(cache_t *cache,
                                 ByteSliceView checksum,
                                 ByteSliceView env,
                                 ByteSliceView msg,
                                 DB db,
                                 GoApi api,
                                 GoQuerier querier,
                                 uint64_t gas_limit,
                                 bool print_debug,
                                 uint64_t *gas_used,
                                 UnmanagedVector *error_msg);

UnmanagedVector ibc_packet_ack(cache_t *cache,
                               ByteSliceView checksum,
                               ByteSliceView env,
                               ByteSliceView msg,
                               DB db,
                               GoApi api,
                               GoQuerier querier,
                               uint64_t gas_limit,
                               bool print_debug,
                               uint64_t *gas_used,
                               UnmanagedVector *error_msg);

UnmanagedVector ibc_packet_receive(cache_t *cache,
                                   ByteSliceView checksum,
                                   ByteSliceView env,
                                   ByteSliceView msg,
                                   DB db,
                                   GoApi api,
                                   GoQuerier querier,
                                   uint64_t gas_limit,
                                   bool print_debug,
                                   uint64_t *gas_used,
                                   UnmanagedVector *error_msg);

UnmanagedVector ibc_packet_timeout(cache_t *cache,
                                   ByteSliceView checksum,
                                   ByteSliceView env,
                                   ByteSliceView msg,
                                   DB db,
                                   GoApi api,
                                   GoQuerier querier,
                                   uint64_t gas_limit,
                                   bool print_debug,
                                   uint64_t *gas_used,
                                   UnmanagedVector *error_msg);

cache_t *init_cache(ByteSliceView data_dir,
                    ByteSliceView supported_features,
                    uint32_t cache_size,
                    uint32_t instance_memory_limit,
                    UnmanagedVector *error_msg);

UnmanagedVector instantiate(cache_t *cache,
                            ByteSliceView checksum,
                            ByteSliceView env,
                            ByteSliceView info,
                            ByteSliceView msg,
                            DB db,
                            GoApi api,
                            GoQuerier querier,
                            uint64_t gas_limit,
                            bool print_debug,
                            uint64_t *gas_used,
                            UnmanagedVector *error_msg);

UnmanagedVector load_wasm(cache_t *cache, ByteSliceView checksum, UnmanagedVector *error_msg);

UnmanagedVector migrate(cache_t *cache,
                        ByteSliceView checksum,
                        ByteSliceView env,
                        ByteSliceView msg,
                        DB db,
                        GoApi api,
                        GoQuerier querier,
                        uint64_t gas_limit,
                        bool print_debug,
                        uint64_t *gas_used,
                        UnmanagedVector *error_msg);

UnmanagedVector new_unmanaged_vector(bool nil, const uint8_t *ptr, uintptr_t length);

void pin(cache_t *cache, ByteSliceView checksum, UnmanagedVector *error_msg);

UnmanagedVector query(cache_t *cache,
                      ByteSliceView checksum,
                      ByteSliceView env,
                      ByteSliceView msg,
                      DB db,
                      GoApi api,
                      GoQuerier querier,
                      uint64_t gas_limit,
                      bool print_debug,
                      uint64_t *gas_used,
                      UnmanagedVector *error_msg);

/**
 * frees a cache reference
 *
 * # Safety
 *
 * This must be called exactly once for any `*cache_t` returned by `init_cache`
 * and cannot be called on any other pointer.
 */
void release_cache(cache_t *cache);

UnmanagedVector save_wasm(cache_t *cache, ByteSliceView wasm, UnmanagedVector *error_msg);

void unpin(cache_t *cache, ByteSliceView checksum, UnmanagedVector *error_msg);
