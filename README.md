# NuPhy Halo75 v2 QMK Mod: Режимы обработки противоположных клавиш (snap tap)

**Русский** | [English](#english-version)

---

## 🎯 Суть проекта

Модификация прошивки QMK для клавиатуры NuPhy Halo75 v2, реализующая два алгоритма обработки одновременного нажатия противоположных клавиш (WASD):

### 🔄 Режим Cancellation (по умолчанию)

```

Клавиши: .. → A. → AD → A.
Отчёт: .. → A. → .D → ..

```

-   **Логика**: Нажатие `D` полностью отменяет `A` без восстановления
-   **Оптимально** для FPS-игр (мгновенная смена направления)

### 🔄 Режим Exclusion

```

Клавиши: .. → A. → AD → A.
Отчёт: .. → A. → .D → A.

```

-   **Логика**: `D` временно исключает `A` с восстановлением при отпускании
-   **Идеально** для платформеров/RPG (кратковременные остановки)

---

## 💡 Управление и индикация

-   **Переключение режимов**: `Fn + Q` (циклическое переключение)
-   **Визуальная индикация**:

    | Режим        | Цвет WASD | Статус    |
    | ------------ | --------- | --------- |
    | Off          | Выключен  | Отключено |
    | Cancellation | Оранжевый | Активен   |
    | Exclusion    | Зелёный   | Активен   |

---

## ⚠️ Важное предупреждение

**Я не являюсь C-разработчиком**. Данная прошивка:

-   Создана в экспериментальных целях
-   Может содержать неоптимальные решения
-   Не гарантирует стабильность работы

**Ответственность**:

> Используете прошивку исключительно на свой страх и риск. Я не несу ответственности за любые последствия, включая:
>
> -   Повреждение оборудования
> -   Игровой бан

**Для разработчиков**:

-   При наличии экспертизы в C/QMK приветствуются PR и улучшения
-   Основная логика реализована в `process_record_user()`

---

## English Version

## 🎯 Project Overview

QMK firmware modification for NuPhy Halo75 v2 implementing dual-mode opposite key handling (snap tap):

### 🔄 Cancellation Mode (default)

```
Keys:      .. → A. → AD → A.
Report:    .. → A. → .D → ..
```

-   **Logic**: `D` completely cancels `A` without restoration
-   **Optimal** for FPS games (instant direction change)

### 🔄 Exclusion Mode

```
Keys:      .. → A. → AD → A.
Report:    .. → A. → .D → A.
```

-   **Logic**: `D` temporarily excludes `A` with restoration on release
-   **Perfect** for platformers/RPGs (temporary stops)

---

## 💡 Controls & Indication

-   **Mode Toggle**: `Fn + Q` (cycle through modes)
-   **Visual Indication**:

    | Mode         | WASD Color | Status   |
    | ------------ | ---------- | -------- |
    | Off          | Disabled   | Inactive |
    | Cancellation | Orange     | Active   |
    | Exclusion    | Green      | Active   |

---

## ⚠️ Critical Disclaimer

**I am not a C developer**. This firmware:

-   Is experimental in nature
-   May contain suboptimal solutions
-   Comes with no stability guarantees

**Liability**:

> Use at your own risk. I am not responsible for any consequences including:
>
> -   Hardware damage
> -   Game ban

**For Developers**:

-   PRs and improvements welcome if you have C/QMK expertise
-   Core logic implemented in `process_record_user()`

---

**License**: MIT
**Author**: i am

```

```
