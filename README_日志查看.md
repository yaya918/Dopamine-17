# Dopamine2 日志查看指南

## 问题
用户没有root权限，无法直接查看Dopamine2日志

## 解决方案

### 1. 启用Dopamine2日志记录（已完成）
已在log.h中启用ENABLE_LOGS宏定义

### 2. 通过iOS设备查看日志

#### 方法A: 使用iTunes/爱思助手查看系统日志
1. 连接iOS设备到电脑
2. 打开iTunes或爱思助手
3. 选择设备 -> 状态
4. 查看"系统日志"或"崩溃报告"

#### 方法B: 使用第三方工具
```bash
# 安装libimobiledevice
brew install libimobiledevice

# 查看设备日志
idevicesyslog
```

#### 方法C: 检查设备上的日志文件
在iOS设备上执行（需要越狱后可用）：
```bash
# 查看Dopamine相关日志
ls -la /var/log/ | grep -i dopa

# 实时查看日志
tail -f /var/log/system.log | grep -i dopa

# 查看崩溃报告
ls -la /var/db/offset/
```

### 3. 重新编译Dopamine2（推荐）

由于当前编译环境不完整，建议：

1. **在macOS上重新编译**：
   ```bash
   # 在macOS上执行
   cd /vol1/1000/yaya/fn-app/Dopamine2-roothide-2.x
   make clean
   make -j4
   ```

2. **刷入新的固件**：
   - 使用重新编译的固件
   - 刷入后Dopamine2会自动记录日志到/var/log/

### 4. 日志位置

Dopamine2启用日志后，日志将保存在：
- `/var/log/Dopamine-时间戳.PID.log`
- `/var/log/Dopamine-error.log`

### 5. 故障排除

如果仍然无法查看日志：

1. **确认Dopamine2已正确安装**
   - 检查是否为iPhone16,2型号
   - 验证固件版本兼容性

2. **检查系统版本**
   - 当前系统：iPhone OS 17.0.3 (21A360)
   - 确保Dopamine2版本支持此系统

3. **重新刷入**
   - 如果是安装问题，重新刷入固件
   - 确保刷入前设备已正确越狱

## 注意事项

1. 启用日志可能会影响性能
2. 日志文件会占用存储空间
3. 建议在排查问题时临时启用，排查完成后关闭