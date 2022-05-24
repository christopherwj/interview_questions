/* angus - Simple program to open,release,read,write */
#include<linux/fs.h>
#include<linux/uaccess.h>
#include<linux/slab.h>
#include<linux/gfp.h>

char *my_buff;
int major = -1;

int my_open(struct inode *inodes, struct file *files);
int my_release(struct inode *inodes, struct file *files);
ssize_t my_read(struct file *file, char __user *buf, size_t len, loff_t *ppos);
ssize_t my_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos);

static const struct file_operations fops = {
        .open = my_open,
        .release = my_release,
        .read = my_read,
        .write = my_write
};


int init_module(void){
        printk("Hi Angus \n");
        major = register_chrdev(0,"hello",&fops);
        printk("Major no : %d \n",major);
        return 0;
}

void cleanup_module(void){
        kfree(my_buff);
        unregister_chrdev(major,"hello");
        printk("Bye Angus \n");
}

int my_open(struct inode *inodes, struct file *files){
        printk("my_open Angus \n");
        return 0;
}

int my_release(struct inode *inodes, struct file *files){
        printk("my_release Angus \n");
        return 0;
}

ssize_t my_read(struct file *file, char __user *buf, size_t len, loff_t *ppos){
        if(copy_to_user(buf,my_buff,len)){ // On success returns 0 and failure returns no of bytes not copied
                return -1;
        }
        printk("my_read Angus \n");
        return len;
}

ssize_t my_write(struct file *file, const char __user *buf, size_t len, loff_t *ppos){
        ssize_t size = len;
        my_buff = kmalloc(100,GFP_KERNEL);
        if(copy_from_user(my_buff,buf,len)){
                return -1;
        }
        printk("my_write Angus \n");
        return size;
}

/* Output */

/* Step : 1 
[ 9079.100187] Hi Angus 
[ 9079.100193] Major no : 250 
[ 9081.321078] my_open Angus 
[ 9081.321157] my_read Angus 
[ 9081.321170] my_write Angus 
[ 9081.321206] my_release Angus 
[ 9131.037905] Bye Angus 
*/

/*Step : 2
mknod hello c 250 0
$cat /proc/devices
*/
