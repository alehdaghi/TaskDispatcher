# TaskDispatcher
Dispatching task Asynchronously or sequentially 


create a dispatcher and dispatching a task

<code>
std::shared_ptr<AsyncDispatcher> dispatcher = std::shared_ptr<AsyncDispatcher>(new AsyncDispatcher);
  
dispatcher->dispatch([]{
        printf("dispatcher1 doing a task! \n");
  });
</code>

make dispatcher list 

<code>
  ThreadDispatcher::pushDispatcher
            (std::shared_ptr<AsyncDispatcher>(new AsyncDispatcher));
  
  ThreadDispatcher::peekDispatcher()->dispatch([]{
        printf("dispatcher1 doing a task!\n");
    });

</code>
