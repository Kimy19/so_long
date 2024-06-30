<h1 align="center"> 42 Seoul - so_long  </h1>
<p align="center">:information_source: MiniLibX Graphics 라이브러리를 사용한 2D Game - Textures, sprites and tiles included. </p>
<p align="center"><img width="750" alt="image" src="https://github.com/Kimy19/so_long/assets/87708360/488572d0-5164-46fc-b557-72b2d272614f"></p>

# Technology Stack

![C](https://img.shields.io/badge/language-C-blue)
![MiniLibX](https://img.shields.io/badge/graphics-MiniLibX-lightgrey)
![2D](https://img.shields.io/badge/type-2D-yellow)



## Index
* [so_long이란?](#what-is-so_long)
* [요구사항](#requirements)
* [실행방법](#how-does-it-work)
	* [Maps](#maps)	
	* [Controls](#controls)
* [테스팅](#how-do-i-test-it)
* [플레이 예시](#play)

<h2 align="center" id="what-is-so_long"> 📌 so_long이란? </h2>

42 Seoul에서 진행한 2D 그래픽 게임 프로젝트입니다.

so_long은 MiniLibx 그래픽 라이브러리를 사용하여 구현한 탑다운 게임입니다. 
인자로 전달되는 맵의 여러 검증, 메모리 누수 방지, 게임 엔지니어링, 창 관리, 이벤트 처리, 스프라이트 애니메이션과 맵 관리를 처리했습니다.

<br>

<h2 align="center" id="requirements"> 요구 사항 </h2>

<p align="center"> :warning: 이 프로젝트는 <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a>을 준수하여 작성되었습니다. </p>
Norm은 42에서 코드 작성 시 따라야 하는 일련의 규칙을 정의한 프로그래밍 표준입니다. 기본적으로 42seoul의 모든 C 프로젝트에 적용되며 이를 통해 가독성 좋은 코드를 작성하는 방법을 배우게 됩니다.

몇 가지 규칙은 다음과 같습니다:

    - 각 함수는 최대 25줄이어야 하며, 함수의 중괄호는 제외합니다.
    
    - 각 줄은 최대 80컬럼까지만 허용되며, 주석도 포함합니다.
    
    - 함수는 최대 4개의 명명된 매개변수만 가질 수 있습니다.
    
    - 함수당 최대 5개의 변수를 선언할 수 있습니다.
    
    - 사용할 수 없는 것들: `for`, `do...while`, `switch`, `case`, `goto`, 삼항 연산자 (`?`), VLAs (Variable Length Arrays).
  

Norminette은 42에서 사용하는 Norm을 검증하는 오픈 소스 파이썬 프로그램입니다.
https://github.com/42School/norminette에서 확인할 수 있습니다.

<br>

<h2 align="center" id="how-does-it-work"> 실행 방법 </h2>

Mac의 내장 mlx라이브러리를 사용하거나 <a href="https://github.com/42Paris/minilibx-linux">MiniLibx</a> 기능을 설치한 후에 게임을 플레이할 수 있습니다.

먼저 프로젝트를 컴파일합니다
```bash
make
```
보너스 버전을 플레이하고 싶다면:
```
make bonus
```
이후 .ber형식의 맵 파일을 인자로 ./so_long을 실행합니다:
```
./so_long /map.ber
```
보너스 버전의 경우:
```
./so_long_bonus map_bonus.ber

```

<br>

<h2 id="maps" align="center"> Maps 🗺 </h2>   

아래 규칙을 준수하는 한 모든 종류의 맵을 파싱할 수 있습니다
맵은 .ber 파일이어야 합니다.

다음 문자만 포함할 수 있습니다:


| CHAR |	OBJECT   |
| --------- | ---------- |
| 1         |   Wall   |
| C	        | Heart |
| E	        |   Exit  |
| P         |   Player  |      
| 0         |   Floor     |
    
보너스의 경우 추가 문자를 통해 적을 구현했습니다 - 적을 마주치면 게임에서 패배합니다.
    
| CHAR |	OBJECT   |
| --------- | ---------- |
| X         |   Snake    |


맵은 직사각형이어야 하며, 벽('1')으로 둘러싸여야 합니다.

맵에는 최소 하나의 출구, 하나의 수집품, 하나의 시작 위치가 있어야 합니다.

예제 맵은 /assets/maps 폴더에서 확인할 수 있습니다.

map.ber의 예:

<img width="449" alt="image" src="https://github.com/Kimy19/so_long/assets/87708360/87dae069-68b1-4af3-bebd-f797533b6add">

이 `.ber` 파일은 다음과 같은 맵을 생성합니다:

<img width="861" alt="image" src="https://github.com/Kimy19/so_long/assets/87708360/6a4b9437-384b-4be9-8c33-43e523902220">

<br>
	
<h2 id="controls" align="center"> 조작법 🕹 </h2>   
    
| KEY |	OBJECT   |
| --------- | ---------- |
| W or ⬆️        |    Move up   |
| A	or ⬅️        |    Move left |
| S	or ⬇️     |    Move down   |
| D or ➡️       |   Move para right|      
| Q or Esc      |   Close the game     | 
    
    
WASD 또는 화살표 키를 사용하여 이동합니다.

모든 하트를 모으면 출구가 열리며 계단을 통해 탈출할 수 있습니다.

게임 창의 빨간 X를 클릭하거나 Q 또는 Esc를 눌러 게임을 종료할 수 있습니다.

<h2 align="center" id="how-do-i-test-it"> 테스트 내용 🛠 </h2>  

올바른 게임 동작을 위해 다양한 맵으로 다음 케이스들에 대해 테스트를 진행했습니다.

- 벽에 부딪히면 움직임이 막히는지, 또는 멈춘 상태에서도 이동 횟수 카운터가 증가하는지 확인

- 모든 코인을 모으지 않고 출구로 이동
  
- 같은 경로를 최소 한 번 이상 통과
  
- 화살표 키와 WASD 키를 사용하여 이동
  
- 창의 빨간 X를 클릭하거나 Esc 또는 Q를 눌러 창이 닫히는지 확인
  
- 창을 최소화하고 다시 열어도 정상 작동
  
- 메모리 누수가 있는지 확인
  
- 맵 검증 테스트
  맵이 없는 경우, 벽으로 인해 경로가 없는 경우, 인자가 없는 경우, 여러 인자가 있는 경우, 잘못된 확장자를 가진 경우, 빈 줄이 있는 맵, 잘못된 맵 파라미터, W 누락, C 누락, E 누락, P 누락, 추가적인 P,E가 있는 경우

테스팅 프로그램 사용 [Tester](https://github.com/augustobecker/so_long_tester).

clone the Tester

```
git clone https://github.com/augustobecker/so_long_tester
```

폴더이동 및 make 명령어 실행:

```
cd so_long_tester
make
```

맵 관련 테스트 실행 결과

![image](https://user-images.githubusercontent.com/81205527/179400332-9e80f631-7d46-464b-a0eb-e481b48ad6b4.png)


<br>


<h2 align="center" id="play"> 게임 플레이 🎮 </h2>

적과 관련된 sprite 애니메이션이 적용된 bonus 버전 플레이 영상


![so_long](https://github.com/Kimy19/so_long/assets/87708360/d08e5b57-27ee-4a66-bcac-df670dc47e7b)


<br>


