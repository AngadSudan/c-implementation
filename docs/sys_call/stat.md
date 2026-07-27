# Stat systemcall

stat systemcall is used inorder to query the metadata for a given file. The content usually involves many fields including type,size,ownership,permissions and time stamp.

## Syntax for stat systemcall

```c
int stat(const char* path, struct stat* buf);
```

- `path` - refers to the path for which stat needs to be looked up
- `buf` - refers to the buffer in which the metadata will be provided. It has to be of type struct stat

### struct stat format

```c
struct stat {
	mode_t st_mode; // file system permissions
	ino_t st_ino; // inode number
	dev_t st_dev; // identifier of device of containing file
	dev_t st_rdev; // devide identifier
	nlink_t	st_nlink; // number of hard links
	uid_t st_uid; // user id of the owner
	gid_t st_gid; // primary grp id of the owner
	off_t st_size; // total file size in bytes
	struct timespec	st_atim; // last access time
	struct timespec	st_mtim; // last modify time
	struct timespec st_ctim; // last status change time
	blksize_t st_blksize; // prefered block size for the file
	blkcnt_t st_blocks; // number of blocks associated
};
```
