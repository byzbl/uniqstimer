# uniqstimer

五个轮
每个轮里面有256个槽
精度1MS

总共256*5=1280个槽
总共是2^40=1,099,511,627,776MS
=12,725.829025185天
=34.865285年

34年，应该一般的场景够用了

TIMER有一个问题：如果频繁删除时间非常非常长的定时器，会导致进程的内存会越来越多
有很多定时器被标记为Killed状态，躺在高级的时间轮里面，要轮到的时候才会清。
不过一百万CPP吃内存只到7MB，GO吃的比较多140多MB。应该一般可以接受。

如果是在MMO里用，添加TIMER的时候尽量避开非常频繁地删除时间特别长的定时器

相同的TimerId不能重复
可以在_helper里面自己定义用池或者是定义分配和释放策略

测试先开一个根节点timer，然后在这个根节点的OnTimer里面创建母Timer，
	再在母timer里面随机删除和创建定时器。
测试有一定的时间误差，时间精度为100MS
