# 프로세스 (Process)

## 1. 프로세스란?
- 프로세스는 **실행 중인 프로그램**이다.
- 프로그램은 디스크에 저장된 정적인 파일이고, 이것이 메모리에 올라와 실행되면 프로세스가 된다.
- 운영체제는 프로세스 단위로 CPU, 메모리 같은 자원을 할당한다.
- 각 프로세스는 독립된 주소 공간을 가지며, 고유한 번호인 PID(Process ID)로 구분된다.

## 2. 프로세스의 메모리 구조
| 영역 | 저장되는 것 | 특징 |
|------|------------|------|
| Stack | 지역 변수, 함수 매개변수, 복귀 주소 | 함수 호출 시 생성, 높은 주소 → 낮은 주소로 자람 |
| Heap | `malloc` 등으로 동적 할당한 메모리 | 낮은 주소 → 높은 주소로 자람 |
| BSS | 초기화되지 않은 전역·static 변수 | 0으로 초기화됨 |
| Data | 초기화된 전역·static 변수 | 프로그램 시작 시 값이 정해짐 |
| Code (Text) | 실행할 기계어 코드 | 읽기 전용 |

- Stack과 Heap은 서로를 향해 자라기 때문에 그 사이 공간을 함께 사용한다.

## 3. 프로세스 상태
- **New**: 프로세스가 생성되는 중
- **Ready**: CPU를 할당받기를 기다리는 중
- **Running**: CPU를 할당받아 실행 중
- **Waiting (Blocked)**: I/O 완료 같은 이벤트를 기다리는 중
- **Terminated**: 실행이 끝남

### 상태 전이
- Ready → Running: 스케줄러가 CPU를 할당 (dispatch)
- Running → Ready: 할당 시간 만료(timeout) 또는 인터럽트
- Running → Waiting: I/O 요청 등 이벤트 대기
- Waiting → Ready: 기다리던 이벤트 완료
- Running → Terminated: 실행 종료 (exit)

## 4. PCB (Process Control Block)

## 5. 문맥 교환 (Context Switch)