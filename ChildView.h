
// ChildView.h : CChildView 类的接口
//


#pragma once

#include "PipeManage.h"
#include "Bird.h"
#include <fstream>


// CChildView 窗口

class CChildView : public CWnd
{
// 构造
public:
	CChildView();

// 特性
public:
	//获取距离小鸟最近的水管
	void getNearest();
	//碰撞检测
	bool collisionDetect();
	//自动控制游戏
	void autoPlay();
	//重置游戏
	void reset();
	//更新 Q 矩阵
	void updateQ(bool isLive);

	CImage birdImage;
	CImage background;
	CImage topPipe, bottomPipe, pipe;
	CRect windowsSize;
	CRect birdPos;
	CDC cacheDC; //缓冲DC
	CBitmap cacheBitmap; //缓冲位图
	PipeManage *pipesManage;
	Bird bird;
	bool isFirstDraw;//是否是第一次绘制
	bool isKeyUP;//判断绘制之前是否按建
	std::vector<Pipe> pipes;//保存存在的所以水管
	bool isHaveNearestPipe;//是否存在最近的水管
	int nearestX, nearestY;//距离小鸟最近的水管坐标

	//Q矩阵
	float qLearning[500][1000][2];//分别代表与最近水管的垂直距离、水平距离和两种动作
	float argment;//学习参数
	int reward , failed;//奖励和惩罚值
	int currentAction, previousAction;//现在和过去采取的行动
	int currentPipeX, currentPipeY;//最近的水管坐标（没有通过的）
	int prePipeX, prePipeY;//过去的最近的水管坐标（没有通过的）
	std::ofstream QFile;
	int index;

// 操作
public:
	void transparentPNG(CImage *png);  

// 重写
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 实现
public:
	virtual ~CChildView();

	// 生成的消息映射函数
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnClose();
};

