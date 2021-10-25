import numpy as np
import json
import matplotlib.pyplot as plt


# # 读入训练数据
# datafile = './housing.data'
# data = np.fromfile(datafile,sep=' ') # 读入的数据是一维的
# # print(data)
# feature_names = [ 'CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE','DIS',
#                  'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV' ]
# feature_num = len(feature_names)
# data = data.reshape([data.shape[0] // feature_num , feature_num])
# # print(data.shape) # (506, 14)
#
# # 划分数据集和测试集
# ratio = 0.8
# offset = int(data.shape[0] * ratio )
# traing_data = data[:offset]
# # print(traing_data.shape) # (404, 14)
#
# # 数据归一化处理
# # 法1
# # maximums , minimums = traing_data.max(axis = 0) , traing_data.min(axis = 0) # axis = 0 : 列;
# # for i in range(feature_num):
# #     data[:,i] = (data[:,i] - minimums[i]) / (maximums[i] - minimums[i])
# # 法2
# maximums , minimums , avgs = traing_data.max(axis = 0),traing_data.min(axis = 0),traing_data.sum(axis = 0) / traing_data.shape[0]
# for i in range(feature_num):
#     data[:,i] = (data[:,i] - avgs[i]) / (maximums[i] - minimums[i])

# 封装

def load_data():
    # 从文件导入数据
    datafile = './housing.data'
    data = np.fromfile(datafile, sep=' ')

    # 每条数据包括14项，其中前面13项是影响因素，第14项是相应的房屋价格中位数
    feature_names = ['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE',
                     'DIS', 'RAD', 'TAX', 'PTRATIO', 'B', 'LSTAT', 'MEDV']
    feature_num = len(feature_names)

    # 将原始数据进行Reshape，变成[N, 14]这样的形状
    data = data.reshape([data.shape[0] // feature_num, feature_num])

    # 将原数据集拆分成训练集和测试集
    # 这里使用80%的数据做训练，20%的数据做测试
    # 测试集和训练集必须是没有交集的
    ratio = 0.8
    offset = int(data.shape[0] * ratio)
    training_data = data[:offset]
    '''
    # 计算train数据集的最大值，最小值
    maximums, minimums= training_data.max(axis=0),training_data.min(axis=0)
    # 对数据进行归一化处理
    for i in range(feature_num):
        data[:, i] = (data[:, i] - minimums[i]) / (maximums[i] - minimums[i])

    '''
    # 计算train数据集的最大值，最小值，平均值
    maximums, minimums, avgs = training_data.max(axis=0), training_data.min(axis=0), \
                               training_data.sum(axis=0) / training_data.shape[0]

    # 对数据进行归一化处理
    for i in range(feature_num):
        # print(maximums[i], minimums[i], avgs[i])
        data[:, i] = (data[:, i] - avgs[i]) / (maximums[i] - minimums[i])

    # 训练集和测试集的划分比例
    training_data = data[:offset]
    test_data = data[offset:]
    return training_data, test_data

# 获取数据
training_data , test_data = load_data()
x = training_data[:, :-1]
y = training_data[:, -1:]



# 模型设计
w = [0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, -0.1, -0.2, -0.3, -0.4, 0.0] # 假设任意给出
w = np.array(w).reshape([13,1])

x1 = x[0]
t = np.dot(x1,w) # 点乘w * x1
b = -0.2
z = t + b

class Network(object):
    def __init__(self,num_of_weight):
        # 随机产生w的初始值
        # 为了保持程序每次运行结果的一致性，
        # 此处设置固定的随机数种子
        np.random.seed(0)
        self.w = np.random.randn(num_of_weight,1)
        self.b = 0
    def forward(self,x):
        z = np.dot(x,self.w) + self.b
        return z
    def loss(self,z,y):
        error = z - y
        cost = error * error
        cost = np.mean(cost)
        return cost

    def gradient(self, x, y):
        z = self.forward(x)
        gradient_w = (z - y) * x
        gradient_w = np.mean(gradient_w, axis=0)
        gradient_w = gradient_w[:, np.newaxis]
        gradient_b = (z - y)
        gradient_b = np.mean(gradient_b)

        return gradient_w, gradient_b

    def update(self, gradient_w, gradient_b, eta=0.01):
        self.w = self.w - eta * gradient_w
        self.b = self.b - eta * gradient_b

    def train(self, x, y, iterations=100, eta=0.01):
        losses = []
        for i in range(iterations):
            z = self.forward(x)
            L = self.loss(z, y)
            gradient_w, gradient_b = self.gradient(x, y)
            self.update(gradient_w, gradient_b, eta)
            losses.append(L)
            if (i + 1) % 10 == 0:
                print('iter {}, loss {}'.format(i, L))
        return losses

    # def update(self, gradient_w5, gradient_w9, eta=0.01):
    #     net.w[5] = net.w[5] - eta * gradient_w5
    #     net.w[9] = net.w[9] - eta * gradient_w9
    #
    # def train(self, x, y, iterations=100, eta=0.01):
    #     points = []
    #     losses = []
    #     for i in range(iterations):
    #         points.append([net.w[5][0], net.w[9][0]])
    #         z = self.forward(x)
    #         L = self.loss(z, y)
    #         gradient_w, gradient_b = self.gradient(x, y)
    #         gradient_w5 = gradient_w[5][0]
    #         gradient_w9 = gradient_w[9][0]
    #         self.update(gradient_w5, gradient_w9, eta)
    #         losses.append(L)
    #         if i % 50 == 0:
    #             print('iter {}, point {}, loss {}'.format(i, [net.w[5][0], net.w[9][0]], L))
    #     return points, losses

# 获取数据
train_data, test_data = load_data()
x = train_data[:, :-1]
y = train_data[:, -1:]
# 创建网络
net = Network(13)
num_iterations=1000
# 启动训练
losses = net.train(x,y, iterations=num_iterations, eta=0.01)

# 画出损失函数的变化趋势
plot_x = np.arange(num_iterations)
plot_y = np.array(losses)
plt.plot(plot_x, plot_y)
plt.show()


# 获取数据
# train_data, test_data = load_data()
# x = train_data[:, :-1]
# y = train_data[:, -1:]
# # 创建网络
# net = Network(13)
# num_iterations=2000
# # 启动训练
# points, losses = net.train(x, y, iterations=num_iterations, eta=0.01)
#
# # 画出损失函数的变化趋势
# plot_x = np.arange(num_iterations)
# plot_y = np.array(losses)
# plt.plot(plot_x, plot_y)
# plt.show()






# net = Network(13) # num_of_weight
# x1 = x[0]
# y1 = y[0]
# z = net.forward(x1)
# print(z)

# x1 = x[0:3]
# y1 = y[0:3]
# z = net.forward(x1)
# print('predict: ',z)
# loss = net.loss(z,y1)
# print('loss: ',loss)

# net = Network(13)
# losses = []
# w5 = np.arange(-160.0 , 160.0 ,1.0)
# w9 = np.arange(-160.0 , 160.0 ,1.0)
# losses = np.zeros([len(w5),len(w9)])
#
# for i in range(len(w5)):
#     for j in range(len(w9)):
#         net.w[5] = w5[i]
#         net.w[9] = w9[j]
#         z = net.forward(x)
#         loss = net.loss(z,y)
#         losses[i,j] = loss
#
# # 作图
# import matplotlib.pyplot as plt
# from mpl_toolkits.mplot3d import Axes3D
# fig = plt.figure()
# ax = Axes3D(fig)
#
# w5,w9 = np.meshgrid(w5,w9)
#
# ax.plot_surface(w5,w9,losses, rstride=1, cstride=1, cmap='rainbow')
# plt.show()


# net = Network(13)
# x1 = x[0]
# y1 = y[0]
# z1 = net.forward(x1)
# print('x1 {}, shape {}'.format(x1, x1.shape))
# print('y1 {}, shape {}'.format(y1, y1.shape))
# print('z1 {}, shape {}'.format(z1, z1.shape))