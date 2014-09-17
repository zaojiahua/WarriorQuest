/****************************************************************************
 Copyright (c) 2013-2014 Chukong Technologies Inc.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "lua_cocos2dx_3d_manual.h"
#include "lua_cocos2dx_3d_auto.hpp"
#include "CCLuaEngine.h"
#include "LuaBasicConversions.h"

//add 2 return value and extand this function
int lua_cocos2dx_camera_unproject(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Camera* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Camera",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Camera*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_Camera_unproject'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        cocos2d::Size arg0;
        cocos2d::Vec3 arg1;
        cocos2d::Vec3 arg2;

        ok &= luaval_to_size(tolua_S, 2, &arg0, "cc.Camera:unproject");

        ok &= luaval_to_vec3(tolua_S, 3, &arg1);

        ok &= luaval_to_vec3(tolua_S, 4, &arg2);
        
        if(!ok)
            return 0;
        cobj->unproject(arg0, &arg1, &arg2);

        vec3_to_luaval(tolua_S, arg2);
        
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.Camera:unproject",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_Camera_unproject'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_3d_AABB_intersects(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::AABB* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.AABB",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::AABB*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_AABB_intersects'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::AABB *arg0;
        
        ok &= luaval_to_object<cocos2d::AABB>(tolua_S, 2, "cc.AABB",&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->intersects(*arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.AABB:intersects",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_AABB_intersects'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_3d_AABB_merge(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::AABB* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.AABB",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::AABB*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_AABB_merge'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::AABB *arg0;
        
        ok &= luaval_to_object<cocos2d::AABB>(tolua_S, 2, "cc.AABB",&arg0);
        if(!ok)
            return 0;
        cobj->merge(*arg0);
        return 0;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.AABB:merge",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_AABB_merge'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_3d_OBB_intersects(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::OBB* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.OBB",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::OBB*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_OBB_intersects'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        cocos2d::OBB *arg0;
        
        ok &= luaval_to_object<cocos2d::OBB>(tolua_S, 2, "cc.OBB",&arg0);
        if(!ok)
            return 0;
        bool ret = cobj->intersects(*arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.OBB:intersects",argc, 1);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_OBB_intersects'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_3d_OBB_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::OBB* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            cocos2d::AABB* arg0;
            ok &= luaval_to_object<cocos2d::AABB>(tolua_S, 2, "cc.AABB",&arg0);
            
            if (!ok) { break; }
            cobj = new cocos2d::OBB(*arg0);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.OBB");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj = new cocos2d::OBB();
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.OBB");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            const cocos2d::Vec3* arg0;
            ok &= luaval_to_object<const cocos2d::Vec3>(tolua_S, 2, "cc.Vec3",&arg0);
            
            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "cc.OBB:OBB");
            
            if (!ok) { break; }
            cobj = new cocos2d::OBB(arg0, arg1);
            tolua_pushusertype(tolua_S,(void*)cobj,"cc.OBB");
            tolua_register_gc(tolua_S,lua_gettop(tolua_S));
            return 1;
        }
    }while(0);
    ok  = true;
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n",  "cc.OBB:OBB",argc, 2);
    return 0;
    
#if COCOS2D_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_OBB_constructor'.",&tolua_err);
#endif
    
    return 0;
}

int lua_cocos2dx_3d_Sprite3D_getAABB(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Sprite3D* cobj = nullptr;
    bool ok  = true;
    
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif
    
    
#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Sprite3D",0,&tolua_err)) goto tolua_lerror;
#endif
    
    cobj = (cocos2d::Sprite3D*)tolua_tousertype(tolua_S,1,0);
    
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_3d_Sprite3D_getAABB'", nullptr);
        return 0;
    }
#endif
    
    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
            return 0;
        cocos2d::AABB* ret = const_cast<cocos2d::AABB*>(&(cobj->getAABB()));
        object_to_luaval<cocos2d::AABB>(tolua_S, "cc.AABB", ret);
        return 1;
    }
    CCLOG("%s has wrong number of arguments: %d, was expecting %d \n", "cc.Sprite3D:getAABB",argc, 0);
    return 0;
    
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_3d_Sprite3D_getAABB'.",&tolua_err);
#endif
    
    return 0;
}

static void extendSprite3D(lua_State *L)
{
    lua_pushstring(L, "cc.Sprite3D");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if(lua_istable(L, -1))
    {
        tolua_function(L, "getAABB", lua_cocos2dx_3d_Sprite3D_getAABB);
    }
    lua_pop(L, -3);
}

static void extendOBB(lua_State* L)
{
    lua_pushstring(L, "cc.OBB");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if(lua_istable(L, -1))
    {
        tolua_function(L, "intersects", lua_cocos2dx_3d_OBB_intersects);
        tolua_function(L, "new", lua_cocos2dx_3d_OBB_constructor);
    }
    lua_pop(L, -3);
}

static void extendAABB(lua_State* tolua_S)
{
    lua_pushstring(tolua_S,"cc.AABB");
    lua_rawget(tolua_S,LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        tolua_function(tolua_S, "intersects", lua_cocos2dx_3d_AABB_intersects);
        tolua_function(tolua_S, "merge", lua_cocos2dx_3d_AABB_merge);
    }
    lua_pop(tolua_S, 1);
}

static void extendCamera(lua_State* tolua_S)
{
    lua_pushstring(tolua_S,"cc.Camera");
    lua_rawget(tolua_S,LUA_REGISTRYINDEX);
    if (lua_istable(tolua_S,-1))
    {
        lua_pushstring(tolua_S,"unproject");
        lua_pushcfunction(tolua_S,lua_cocos2dx_camera_unproject);
        lua_rawset(tolua_S,-3);
    }
    lua_pop(tolua_S, 1);
}

int register_cocos3d_module(lua_State* L)
{
    lua_getglobal(L, "_G");
    if (lua_istable(L,-1))//stack:...,_G,
    {
        register_all_cocos2dx_3d(L);
    }
    lua_pop(L, 1);
    
    extendCamera(L);
    extendAABB(L);
    extendOBB(L);
    extendSprite3D(L);

    return 1;
}
