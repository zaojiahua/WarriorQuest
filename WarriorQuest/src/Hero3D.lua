local Hero3D = class("Hero3D", function()
    return require "Base3D".create()
end)

function Hero3D:ctor()
    self._useWeaponId = 0
    self._useArmourId = 0
    self._arm = ""
    self._chest = ""
    self._weapon = ""
end

function Hero3D.create(type)
    
    local hero = Hero3D.new()
    hero:AddSprite3D(type)
    
    -- base
    hero:setRaceType(type)

    --self
    hero._weapon = math.random() .. ""
    
    return hero
end

function Hero3D:AddSprite3D(type)
    
    local filename;
    if type == EnumRaceType.WARRIOR then --warrior
        filename = "Sprite3DTest/ReskinGirl.c3b"
    elseif type == EnumRaceType.ARCHER then --archer
        filename = "Sprite3DTest/ReskinGirl.c3b"
    elseif type == EnumRaceType.SORCERESS then --sorceress
        filename = "Sprite3DTest/ReskinGirl.c3b"
    else
        filename = "Sprite3DTest/orc.c3b" 
    end
    self._sprite3d = cc.Sprite3D:create(filename)
    self:addChild(self._sprite3d)

    --run animation
    local animation = cc.Animation3D:create(filename)
    local animate = cc.Animate3D:create(animation)
    self._sprite3d:runAction(cc.RepeatForever:create(animate))

    --set default equipment
    if type ~= EnumRaceType.DEBUG then
        self:setDefaultEqt()
    end
end

-- set default equipments
function Hero3D:setDefaultEqt()
    local girl_lowerbody = self._sprite3d:getMeshByName("Girl_LowerBody01")
    girl_lowerbody:setVisible(false)
    local girl_shoe = self._sprite3d:getMeshByName("Girl_Shoes01")
    girl_shoe:setVisible(false)
    local girl_hair = self._sprite3d:getMeshByName("Girl_Hair01")
    girl_hair:setVisible(false)
    local girl_upperbody = self._sprite3d:getMeshByName("Girl_UpperBody01")
    girl_upperbody:setVisible(false)
end

--swicth weapon
function Hero3D:switchWeapon()
    self._useWeaponId = self._useWeaponId+1
    if self._useWeaponId > 1 then
        self._useWeaponId = 0;
    end
    if self._useWeaponId == 1 then
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_LowerBody01")
        girl_lowerbody:setVisible(true)
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_LowerBody02")
        girl_lowerbody:setVisible(false)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_Shoes01")
        girl_shoe:setVisible(true)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_Shoes02")
        girl_shoe:setVisible(false)
    else
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_LowerBody01")
        girl_lowerbody:setVisible(false)
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_LowerBody02")
        girl_lowerbody:setVisible(true)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_Shoes01")
        girl_shoe:setVisible(false)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_Shoes02")
        girl_shoe:setVisible(true)
    end
end

--switch armour
function Hero3D:switchArmour()
    self._useArmourId = self._useArmourId+1
    if self._useArmourId > 1 then
        self._useArmourId = 0;

    end
    if self._useArmourId == 1 then
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_Hair01")
        girl_lowerbody:setVisible(true)
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_Hair02")
        girl_lowerbody:setVisible(false)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_UpperBody01")
        girl_shoe:setVisible(true)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_UpperBody02")
        girl_shoe:setVisible(false)
    else
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_Hair01")
        girl_lowerbody:setVisible(false)
        local girl_lowerbody = self._sprite3d:getMeshByName("Girl_Hair02")
        girl_lowerbody:setVisible(true)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_UpperBody01")
        girl_shoe:setVisible(false)
        local girl_shoe = self._sprite3d:getMeshByName("Girl_UpperBody02")
        girl_shoe:setVisible(true)
    end
end


-- get weapon id
function Hero3D:getWeaponID()
    return self._useWeaponId
end

-- get armour id
function Hero3D:getArmourID()
    return self._useArmourId
end

local scheduler = cc.Director:getInstance():getScheduler()

-- find enemy
function Hero3D:FindEnemy2Attack()
    if self._isalive == false then return end 

    if self._target ~= 0 and self._target._isalive then
        if self._statetype == EnumStateType.ATTACK then
            return
        end

        local x1, y1 = self:getPosition()
        local x2, y2 = self.target:getPosition()
        local distance = math.abs(x1-x2)

        if distance < 100 then
            self:setState(EnumStateType.ATTACK)

            local function scheduleAttack(dt)
                if self._isalive == false or self._target == 0 or self._target._isalive == false then
                    scheduler:unscheduleScriptEntry(self._scheduleAttackId)
                    self._scheduleAttackId = 0
                    return          
                end

                local attacker = self
                local defender = self._target

                defender._blood = defender._blood - attacker._attack
                if defender._blood > 0 then
                    if defender._racetype == EnumRaceType.BOSS then
                        local action = cc.Sequence:create(cc.MoveBy:create(0.05, cc.p(10,10)),  cc.MoveBy:create(0.05, cc.p(-10,-10)))
                        defender:runAction(action)
                    else 
                        defender:runAction(cc.RotateBy:create(0.5, 360.0))
                    end     
                else
                    defender._alive = false
                    defender:setState(EnumStateType.DEAD)
                    attacker:setState(EnumStateType.STAND)
                end
            end

            self._scheduleAttackId = scheduler:scheduleScriptFunc(scheduleAttack, self._priority+5, false)            
        end  
    end

    self._target = findAliveMonster()

    if self._target == 0 then
        self._target = findAliveBoss()
    end   
end

return Hero3D