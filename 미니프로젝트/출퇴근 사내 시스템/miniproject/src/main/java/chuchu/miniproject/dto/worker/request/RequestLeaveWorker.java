package chuchu.miniproject.dto.worker.request;

import java.time.LocalDate;

public record RequestLeaveWorker(Long workerId, LocalDate workDate) {
}
