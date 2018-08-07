#ifndef __DEFAULT_SOURCE4_LIBCLI_SMB2_SMB2_PROTO_H__
#define __DEFAULT_SOURCE4_LIBCLI_SMB2_SMB2_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

/* this file contains prototypes for functions that are private 
 * to this subsystem or library. These functions should not be 
 * used outside this particular subsystem! */


/* The following definitions come from ../source4/libcli/smb2/transport.c  */

struct smb2_transport *smb2_transport_init(struct smbcli_socket *sock,
					   TALLOC_CTX *parent_ctx,
					   struct smbcli_options *options);
void smb2_transport_dead(struct smb2_transport *transport, NTSTATUS status);
void smb2_transport_send(struct smb2_request *req);
NTSTATUS smb2_transport_compound_start(struct smb2_transport *transport,
				       uint32_t num);
void smb2_transport_compound_set_related(struct smb2_transport *transport,
					 bool related);
void smb2_transport_credits_ask_num(struct smb2_transport *transport,
				    uint16_t ask_num);
void smb2_transport_idle_handler(struct smb2_transport *transport, 
				 void (*idle_func)(struct smb2_transport *, void *),
				 uint64_t period,
				 void *private_data);

/* The following definitions come from ../source4/libcli/smb2/request.c  */

void smb2_setup_bufinfo(struct smb2_request *req);
struct smb2_request *smb2_request_init(struct smb2_transport *transport, uint16_t opcode,
				       uint16_t body_fixed_size, bool body_dynamic_present,
				       uint32_t body_dynamic_size);
struct smb2_request *smb2_request_init_tree(struct smb2_tree *tree, uint16_t opcode,
					    uint16_t body_fixed_size, bool body_dynamic_present,
					    uint32_t body_dynamic_size);
NTSTATUS smb2_request_destroy(struct smb2_request *req);
bool smb2_request_receive(struct smb2_request *req);
bool smb2_request_is_error(struct smb2_request *req);
bool smb2_request_is_ok(struct smb2_request *req);
bool smb2_oob(struct smb2_request_buffer *buf, const uint8_t *ptr, size_t size);
size_t smb2_padding_size(uint32_t offset, size_t n);
NTSTATUS smb2_grow_buffer(struct smb2_request_buffer *buf, size_t increase);
NTSTATUS smb2_pull_o16s16_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_push_o16s16_blob(struct smb2_request_buffer *buf, 
			       uint16_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_o16s32_blob(struct smb2_request_buffer *buf, 
			       uint16_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_o32s32_blob(struct smb2_request_buffer *buf, 
			       uint32_t ofs, DATA_BLOB blob);
NTSTATUS smb2_push_s32o32_blob(struct smb2_request_buffer *buf, 
			       uint32_t ofs, DATA_BLOB blob);
NTSTATUS smb2_pull_o16s32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_o32s32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_o16As32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_s32o32_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_s32o16_blob(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx, uint8_t *ptr, DATA_BLOB *blob);
NTSTATUS smb2_pull_o16s16_string(struct smb2_request_buffer *buf, TALLOC_CTX *mem_ctx,
				 uint8_t *ptr, const char **str);
NTSTATUS smb2_push_o16s16_string(struct smb2_request_buffer *buf,
				 uint16_t ofs, const char *str);
void smb2_push_handle(uint8_t *data, struct smb2_handle *h);
void smb2_pull_handle(uint8_t *ptr, struct smb2_handle *h);

/* The following definitions come from ../source4/libcli/smb2/session.c  */


/**
  initialise a smb2_session structure
 */
struct smb2_session *smb2_session_init(struct smb2_transport *transport,
				       struct gensec_settings *settings,
				       TALLOC_CTX *parent_ctx);
struct smb2_session *smb2_session_channel(struct smb2_transport *transport,
					  struct gensec_settings *settings,
					  TALLOC_CTX *parent_ctx,
					  struct smb2_session *base_session);
struct tevent_req *smb2_session_setup_spnego_send(
				TALLOC_CTX *mem_ctx,
				struct tevent_context *ev,
				struct smb2_session *session,
				struct cli_credentials *credentials,
				uint64_t previous_session_id);
NTSTATUS smb2_session_setup_spnego_recv(struct tevent_req *req);
NTSTATUS smb2_session_setup_spnego(struct smb2_session *session, 
				   struct cli_credentials *credentials,
				   uint64_t previous_session_id);

/* The following definitions come from ../source4/libcli/smb2/tcon.c  */

struct smb2_tree *smb2_tree_init(struct smb2_session *session,
				 TALLOC_CTX *parent_ctx, bool primary);

/* The following definitions come from ../source4/libcli/smb2/create.c  */

struct smb2_request *smb2_create_send(struct smb2_tree *tree, struct smb2_create *io);
NTSTATUS smb2_create_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx, struct smb2_create *io);
NTSTATUS smb2_create(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_create *io);

/* The following definitions come from ../source4/libcli/smb2/close.c  */

struct smb2_request *smb2_close_send(struct smb2_tree *tree, struct smb2_close *io);
NTSTATUS smb2_close_recv(struct smb2_request *req, struct smb2_close *io);
NTSTATUS smb2_close(struct smb2_tree *tree, struct smb2_close *io);

/* The following definitions come from ../source4/libcli/smb2/connect.c  */

struct tevent_req *smb2_connect_send(TALLOC_CTX *mem_ctx,
				     struct tevent_context *ev,
				     const char *host,
				     const char **ports,
				     const char *share,
				     struct resolve_context *resolve_ctx,
				     struct cli_credentials *credentials,
				     uint64_t previous_session_id,
				     const struct smbcli_options *options,
				     const char *socket_options,
				     struct gensec_settings *gensec_settings);
NTSTATUS smb2_connect_recv(struct tevent_req *req,
			   TALLOC_CTX *mem_ctx,
			   struct smb2_tree **tree);
NTSTATUS smb2_connect_ext(TALLOC_CTX *mem_ctx,
			  const char *host,
			  const char **ports,
			  const char *share,
			  struct resolve_context *resolve_ctx,
			  struct cli_credentials *credentials,
			  uint64_t previous_session_id,
			  struct smb2_tree **tree,
			  struct tevent_context *ev,
			  const struct smbcli_options *options,
			  const char *socket_options,
			  struct gensec_settings *gensec_settings);
NTSTATUS smb2_connect(TALLOC_CTX *mem_ctx,
		      const char *host,
		      const char **ports,
		      const char *share,
		      struct resolve_context *resolve_ctx,
		      struct cli_credentials *credentials,
		      struct smb2_tree **tree,
		      struct tevent_context *ev,
		      struct smbcli_options *options,
		      const char *socket_options,
		      struct gensec_settings *gensec_settings);

/* The following definitions come from ../source4/libcli/smb2/getinfo.c  */

struct smb2_request *smb2_getinfo_send(struct smb2_tree *tree, struct smb2_getinfo *io);
NTSTATUS smb2_getinfo_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			   struct smb2_getinfo *io);
NTSTATUS smb2_getinfo(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		      struct smb2_getinfo *io);
uint16_t smb2_getinfo_map_level(uint16_t level, uint8_t info_class);
struct smb2_request *smb2_getinfo_file_send(struct smb2_tree *tree, union smb_fileinfo *io);
NTSTATUS smb2_getinfo_file_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
				union smb_fileinfo *io);
NTSTATUS smb2_getinfo_file(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, 
			   union smb_fileinfo *io);
struct smb2_request *smb2_getinfo_fs_send(struct smb2_tree *tree, union smb_fsinfo *io);
NTSTATUS smb2_getinfo_fs_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
				union smb_fsinfo *io);
NTSTATUS smb2_getinfo_fs(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, 
			   union smb_fsinfo *io);

/* The following definitions come from ../source4/libcli/smb2/write.c  */

struct smb2_request *smb2_write_send(struct smb2_tree *tree, struct smb2_write *io);
NTSTATUS smb2_write_recv(struct smb2_request *req, struct smb2_write *io);
NTSTATUS smb2_write(struct smb2_tree *tree, struct smb2_write *io);

/* The following definitions come from ../source4/libcli/smb2/read.c  */

struct smb2_request *smb2_read_send(struct smb2_tree *tree, struct smb2_read *io);
NTSTATUS smb2_read_recv(struct smb2_request *req, 
			TALLOC_CTX *mem_ctx, struct smb2_read *io);
NTSTATUS smb2_read(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_read *io);

/* The following definitions come from ../source4/libcli/smb2/setinfo.c  */

struct smb2_request *smb2_setinfo_send(struct smb2_tree *tree, struct smb2_setinfo *io);
NTSTATUS smb2_setinfo_recv(struct smb2_request *req);
NTSTATUS smb2_setinfo(struct smb2_tree *tree, struct smb2_setinfo *io);
struct smb2_request *smb2_setinfo_file_send(struct smb2_tree *tree, union smb_setfileinfo *io);
NTSTATUS smb2_setinfo_file(struct smb2_tree *tree, union smb_setfileinfo *io);

/* The following definitions come from ../source4/libcli/smb2/find.c  */

struct smb2_request *smb2_find_send(struct smb2_tree *tree, struct smb2_find *io);
NTSTATUS smb2_find_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			   struct smb2_find *io);
NTSTATUS smb2_find(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		   struct smb2_find *io);
NTSTATUS smb2_find_level_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			      uint8_t level, unsigned int *count,
			      union smb_search_data **io);
NTSTATUS smb2_find_level(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
			 struct smb2_find *f, 
			 unsigned int *count, union smb_search_data **io);

/* The following definitions come from ../source4/libcli/smb2/ioctl.c  */

struct smb2_request *smb2_ioctl_send(struct smb2_tree *tree, struct smb2_ioctl *io);
NTSTATUS smb2_ioctl_recv(struct smb2_request *req,
			 TALLOC_CTX *mem_ctx, struct smb2_ioctl *io);
NTSTATUS smb2_ioctl(struct smb2_tree *tree, TALLOC_CTX *mem_ctx, struct smb2_ioctl *io);

/* The following definitions come from ../source4/libcli/smb2/logoff.c  */

struct smb2_request *smb2_logoff_send(struct smb2_session *session);
NTSTATUS smb2_logoff_recv(struct smb2_request *req);
NTSTATUS smb2_logoff(struct smb2_session *session);

/* The following definitions come from ../source4/libcli/smb2/tdis.c  */

struct smb2_request *smb2_tdis_send(struct smb2_tree *tree);
NTSTATUS smb2_tdis_recv(struct smb2_request *req);
NTSTATUS smb2_tdis(struct smb2_tree *tree);

/* The following definitions come from ../source4/libcli/smb2/flush.c  */

struct smb2_request *smb2_flush_send(struct smb2_tree *tree, struct smb2_flush *io);
NTSTATUS smb2_flush_recv(struct smb2_request *req, struct smb2_flush *io);
NTSTATUS smb2_flush(struct smb2_tree *tree, struct smb2_flush *io);

/* The following definitions come from ../source4/libcli/smb2/lock.c  */

struct smb2_request *smb2_lock_send(struct smb2_tree *tree, struct smb2_lock *io);
NTSTATUS smb2_lock_recv(struct smb2_request *req, struct smb2_lock *io);
NTSTATUS smb2_lock(struct smb2_tree *tree, struct smb2_lock *io);

/* The following definitions come from ../source4/libcli/smb2/notify.c  */

struct smb2_request *smb2_notify_send(struct smb2_tree *tree, struct smb2_notify *io);
NTSTATUS smb2_notify_recv(struct smb2_request *req, TALLOC_CTX *mem_ctx,
			  struct smb2_notify *io);
NTSTATUS smb2_notify(struct smb2_tree *tree, TALLOC_CTX *mem_ctx,
		     struct smb2_notify *io);

/* The following definitions come from ../source4/libcli/smb2/cancel.c  */

NTSTATUS smb2_cancel(struct smb2_request *r);

/* The following definitions come from ../source4/libcli/smb2/keepalive.c  */

struct smb2_request *smb2_keepalive_send(struct smb2_transport *transport,
					 struct smb2_session *session);
NTSTATUS smb2_keepalive_recv(struct smb2_request *req);
NTSTATUS smb2_keepalive(struct smb2_transport *transport);

/* The following definitions come from ../source4/libcli/smb2/break.c  */

struct smb2_request *smb2_break_send(struct smb2_tree *tree, struct smb2_break *io);
NTSTATUS smb2_break_recv(struct smb2_request *req, struct smb2_break *io);
NTSTATUS smb2_break(struct smb2_tree *tree, struct smb2_break *io);

/* The following definitions come from ../source4/libcli/smb2/util.c  */

NTSTATUS smb2_util_close(struct smb2_tree *tree, struct smb2_handle h);
NTSTATUS smb2_util_unlink(struct smb2_tree *tree, const char *fname);
NTSTATUS smb2_util_rmdir(struct smb2_tree *tree, const char *dname);
NTSTATUS smb2_util_mkdir(struct smb2_tree *tree, const char *dname);
NTSTATUS smb2_util_setatr(struct smb2_tree *tree, const char *name, uint32_t attrib);
int smb2_deltree(struct smb2_tree *tree, const char *dname);
bool smb2_util_handle_equal(const struct smb2_handle h1,
			    const struct smb2_handle h2);
bool smb2_util_handle_empty(const struct smb2_handle h);

/* The following definitions come from ../source4/libcli/smb2/signing.c  */

NTSTATUS smb2_sign_message(struct smb2_request_buffer *buf, DATA_BLOB session_key);
NTSTATUS smb2_check_signature(struct smb2_request_buffer *buf, DATA_BLOB session_key);

/* The following definitions come from ../source4/libcli/smb2/lease_break.c  */

struct smb2_request *smb2_lease_break_ack_send(struct smb2_tree *tree,
                                               struct smb2_lease_break_ack *io);
NTSTATUS smb2_lease_break_ack_recv(struct smb2_request *req,
                                   struct smb2_lease_break_ack *io);
NTSTATUS smb2_lease_break_ack(struct smb2_tree *tree,
                              struct smb2_lease_break_ack *io);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __DEFAULT_SOURCE4_LIBCLI_SMB2_SMB2_PROTO_H__ */
