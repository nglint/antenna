#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <stdio.h>
/*#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_QUADS 0x0007
#define GL_QUAD_STRIP 0x0008
#define GL_POLYGON 0x0009
*/
#define pi 3.4145926


LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hwnd;
    HDC hDC;
    HGLRC hRC;
    MSG msg;
    BOOL bQuit = FALSE;
    float theta = 0.0f;

    /* register window class */
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_OWNDC;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = "GLSample";
    wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


    if (!RegisterClassEx(&wcex))
        return 0;
int f=2400000000,N=8,v=1,ph2=0,th2=0;
    int a[10]={1 ,9 ,36 ,84 ,126 ,126, 84, 36 ,9, 1};
float x[64800]={0},y[64800]={0},th=0,lan=f/300000000,k=(pi*2),d,B,z[64800]={0},max=0,rx,ry;
N=10;
B=0;
B=B*(pi/180);
d=(1/4);

    hwnd = CreateWindowEx(0,"GLSample","OpenGL Sample",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,
                          1920,
                          1080,
                          NULL,
                          NULL,
                          hInstance,
                          NULL);

    ShowWindow(hwnd, nCmdShow);

    /* enable OpenGL for the window */
    EnableOpenGL(hwnd, &hDC, &hRC);

    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
          

            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            glClear(GL_COLOR_BUFFER_BIT);
 POINT po1,po2;
GetCursorPos(&po1);
            glPushMatrix();
            unsigned long long ff;
if(GetKeyState('W')<0)N++,v=1;
if(GetKeyState('S')<0){
    N--,v=1;
    if(N<0)N=0;
}
if(GetKeyState('E')<0)B+=(pi/180),v=1;
if(GetKeyState('D')<0)B-=(pi/180),v=1;
if(GetKeyState('Q')<0)d*=1.1,v=1;
if(GetKeyState('A')<0)d/=1.1,v=1;
if(v)printf("d=lan*%f N=%f ph=%f\n",d,N,B);
            if(GetKeyState(VK_LBUTTON)<0)
            {
                if(po1.x>po2.x)rx=1,th2+=5,th2%=360;
                else if (po1.x<po2.x)rx=-1,th2-=5,th2%=360;
                else rx=0;
                if(po1.y>po2.y)ry=1,ph2-=5,ph2%=180;
                else if (po1.y<po2.y)ry=-1,ph2+5,ph2%=180;
                else ry=0;
            po2=po1 ;
            v=1;
             if(ry+rx!=0)  glRotatef(4, rx, ry, 0);
            }
            else
       glRotatef(1, 1, 1, 1);
;
int n=0,I=0;
glBegin(GL_LINE_STRIP);
glColor3f(1, 0,0);   glVertex3f(1,0,0);glVertex3f(-1,0,0);
  glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0, 1,0);   glVertex3f(0,1,0);glVertex3f(0,-1,0);
  glEnd();
glBegin(GL_LINE_STRIP);
glColor3f(0, 0,1);   glVertex3f(0,0,1);glVertex3f(0,0,-1);
  glEnd();
glBegin(GL_LINE_LOOP);

if(v){max=0;
for(float ph=0;ph<180;ph+=1){

            for(float th=0,m=0;th<360;th++,n++){;
x[I]=0,y[I]=0,z[I]=0;

float s2=0;
s2=((k*d*cos((th)*(pi/180))*sin((ph)*(pi/180)))+B);


           for(int i=1;i<=N;i++){
            x[I]=x[I]+((cos(s2*(i-1))));
            y[I]=y[I]+((sin(s2*(i-1))));
          

           }
         float   r=sqrt((x[I]*x[I])+(y[I]*y[I]));
if(r>max)max=r;

z[I]=(r*sin((th)*(pi/180))/10)*sin((ph)*(pi/180));//xxx/yyyy
y[I]=(r*cos((th)*(pi/180))/10)*sin((ph)*(pi/180));//yyyy/zzz
x[I]=(r*cos((ph)*(pi/180))/10);//zzz
//z[I]=(z[I]*cos((ph)*(pi/180)))+(x[I]*sin((ph)*(pi/180)));
//x[I]=(z[I]*-sin((ph)*(pi/180)))+(x[I]*cos((ph)*(pi/180)));


I++;

}}}
v=0;
glBegin(GL_LINE_LOOP);
for(int i=0;i<64800;i+=2)
{
float r=(x[i]*x[i])+(y[i]*y[i])+(z[i]*z[i]);
  float h=(r/max)*16777216;
unsigned int hh=h;



float rr,b,g;

rr=((hh>>16)&0xff);
g=((hh>>8)&0xff);
b=(hh&255);

rr=rr/255;
b=b/255;
g=g/255;

if(hh>0x0fffff)b/=2,g/=2;


                glColor3f(r, g,b);   glVertex4f(z[i],y[i],x[i],1);



}

            glEnd();

          //  glPopMatrix();

            SwapBuffers(hDC);

            theta += 1.0f;
            Sleep (1);
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL(hwnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow(hwnd);

    return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CLOSE:
            PostQuitMessage(0);
        break;

        case WM_DESTROY:
            return 0;

        case WM_KEYDOWN:
        {
            switch (wParam)
            {
                case VK_ESCAPE:
                    PostQuitMessage(0);
                break;
            }
        }
        break;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }

    return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
    PIXELFORMATDESCRIPTOR pfd;

    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC(hwnd);

    /* set the pixel format for the DC */
    ZeroMemory(&pfd, sizeof(pfd));

    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW |
                  PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;

    iFormat = ChoosePixelFormat(*hDC, &pfd);

    SetPixelFormat(*hDC, iFormat, &pfd);
/* create and enable the render context (RC) */
    *hRC = wglCreateContext(*hDC);

    wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL (HWND hwnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(hRC);
    ReleaseDC(hwnd, hDC);
}
