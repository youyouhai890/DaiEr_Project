

-- coroutine_test.lua 文件
co = coroutine.create(		--创建协同程序，返回协同程序， 参数是一个函数，当和resume配合使用的时候就唤醒函数调用
    function(i)
        print(i);
    end
)

--重启协同程序，和create配合使用	,	应用部分
coroutine.resume(co, 111)   -- 1
--查看协同程序的状态
print(coroutine.status(co))  -- dead
print("----------------------------------------------------------------------------")

--创建协同程序，返回一个函数，一旦你调用这个函数，就进入协同程序，和create功能重复
co = coroutine.wrap(
    function(i)
        print(i);
    end
)

co(222)	--启用协成方法	,	应用部分

print("================================================================================")

co2 = coroutine.create(
    function()
        for i=1,10 do
            print(i)
            if i == 3 then
                print(coroutine.status(co2))  --running
                print(coroutine.running()) --thread:XXXXXX
            end
            coroutine.yield()
        end
    end
)

coroutine.resume(co2) --1
coroutine.resume(co2) --2
coroutine.resume(co2) --3

print(coroutine.status(co2))   -- suspended
print(coroutine.running())

print("----------")
