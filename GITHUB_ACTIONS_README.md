# Dopamine GitHub Actions 构建和签名工作流

## 概述

本项目包含两个GitHub Actions工作流，用于自动化Dopamine的构建、签名和发布：

1. **main.yml** - 基础构建工作流
2. **build-and-sign.yml** - 增强版构建和签名工作流

## 工作流功能

### build-and-sign.yml 工作流包含以下步骤：

1. **环境设置** - 配置Xcode和必要的工具
2. **代码检出** - 获取最新代码和子模块
3. **依赖安装** - 安装THEOS和其他构建依赖
4. **构建Dopamine** - 使用Makefile构建项目
5. **签名IPA** - 使用ldid对构建的IPA进行签名
6. **上传工件** - 上传签名后的IPA文件
7. **创建发布** - 如果是标签触发，创建GitHub发布

### testflight.yml 工作流（可选）：
- 从构建工件下载IPA
- 上传到App Store Connect
- 发布到TestFlight

## 使用方法

### 1. 自动触发

工作流会在以下情况自动触发：
- 推送到任何分支
- 创建Pull Request
- 手动触发工作流
- 定期执行（每月）

### 2. 手动触发

1. 进入GitHub仓库
2. 点击Actions选项卡
3. 选择"Dopamine: build, sign and upload"
4. 点击"Run workflow"

### 3. 标签触发

要创建发布版本，请创建标签：
```bash
git tag -a v1.0.0 -m "Release version 1.0.0"
git push origin v1.0.0
```

## 环境变量

要使用TestFlight上传功能，需要设置以下环境变量：

1. **ISSUER_ID** - App Store Connect的发行者ID
2. **KEY_ID** - API密钥ID
3. **PRIVATE_KEY** - API私钥

这些变量在GitHub仓库的Settings → Secrets中设置。

## 输出文件

构建完成后，会在以下位置找到签名后的IPA文件：
- 上传的工件：`Dopamine-Signed.ipa`
- 如果是标签触发，还会创建GitHub发布并上传IPA作为附件

## 注意事项

1. **开发者证书** - 确保有有效的iOS开发者证书
2. **签名** - 使用ldid进行签名，确保符合Apple的要求
3. **测试** - 建议先在测试设备上验证签名后的IPA
4. **安全** - 不要将私钥等敏感信息提交到仓库

## 故障排除

如果构建失败，请检查：
1. Xcode版本是否正确
2. 依赖是否正确安装
3. 网络连接是否正常
4. 是否有权限访问GitHub Actions资源