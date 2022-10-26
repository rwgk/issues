class Wrapper():
    serviceId = "mmocr"
    version = "backup.0"


    '''
    服务初始化
    @param config:
        插件初始化需要的一些配置，字典类型
        key: 配置名
        value: 配置的值
    @return
        ret: 错误码。无错误时返回0
    '''

    def wrapperInit(cls, config: {}) -> int:
        import torch
        print(config)

        print("Initializing ..")
        return 0

    def wrapperFini(cls) -> int:
        return 0
