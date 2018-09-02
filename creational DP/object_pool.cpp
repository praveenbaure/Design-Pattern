//
// Created by praveen balure on 02/09/18.
//

#include <cstdio>
#include <queue>

class Resource{
public:
    Resource() {
        printf("Resource created\n");
    }

    virtual ~Resource() {
        printf("Resource destructed\n");
    }
};

class object_pool{
private:
    static object_pool * instance;
    std::queue<Resource *> resource_queue;
    object_pool(){}

public:
    static object_pool *create_object_pool();
    Resource * get_resource();
    void release_resource(Resource *res);
    size_t resource_in_market();
    void clear_pool();
};

object_pool *object_pool::instance = nullptr;


object_pool *object_pool::create_object_pool() {
    if(nullptr ==  instance)
        instance = new object_pool;
    return instance;
}

Resource *object_pool::get_resource() {
    Resource *temp;
    if(resource_queue.empty())
        temp =  new Resource;
    else {
        temp = resource_queue.front();
        resource_queue.pop();
    }
    return temp;
}

void object_pool::release_resource(Resource *res) {
    resource_queue.push(res);
}

size_t object_pool::resource_in_market() {
    return resource_queue.size();
}

void object_pool::clear_pool() {
    while(!resource_queue.empty()){
        delete resource_queue.front();
        resource_queue.pop();
    }
}

/*
 * Below in main program we can see create_object_pool is singleton object
 * all the resources created by both the pool object will be added to same pool
 * and also released into same pool
 */
int main(){
    object_pool * pool1  =  object_pool::create_object_pool();
    object_pool * pool2  =  object_pool::create_object_pool();

    Resource * res1 = pool1->get_resource();
    Resource * res2 = pool2->get_resource();
    Resource * res3 = pool1->get_resource();
    pool1->release_resource(res1);
    printf("Resource free by pool1 %d\n",
           static_cast<int>(pool1->resource_in_market()));
    printf("Resource free by pool2 %d\n",
           static_cast<int>(pool2->resource_in_market()));
    pool1->release_resource(res3);
    pool1->release_resource(res2);
    pool1->clear_pool();
    return 1;
}
