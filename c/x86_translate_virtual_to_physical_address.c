taskpid = find_get_pid(curpid);
task = pid_task(taskpid, PIDTYPE_PID );
mm = get_task_mm(task);
down_read(&mm->mmap_sem);

start_vaddr = vaddr;
end_vaddr = 0xC0000000;

while( start_vaddr < end_vaddr){
    u32 end;

    end = (( start_vaddr + PMD_SIZE) & PMD_MASK);

    if( end < start_vaddr || end > end_vaddr)
        end = end_vaddr;

    ret = walk_pgd(start_vaddr, end, mm);
    if(ret != 0){
        printk("ret: %08x \n", ret);
        break;
    }

    start_vaddr = end;

}

up_read(&mm->mmap_sem);

paddr = ret;
kaddr = __va(paddr);
mmput(mm);
